#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFF_SIZE 64

/**
 * print_error - prints the error message to stderr
 * @msg: the error message to print
 */
void print_error(char *msg)
{
    dprintf(STDERR_FILENO, "%s\n", msg);
}

/**
 * print_elf_header - prints the ELF header information
 * @header: the ELF header to print
 */
void print_elf_header(Elf64_Ehdr header)
{
    int i;

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%s", header.e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
    printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "unknown");
    printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "unknown");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header.e_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
    printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);
    printf("\n");
}

/**
 * main - entry point
 * @argc: the number of command-line arguments
 * @argv: an array of command-line argument strings
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    int fd, read_bytes;
    Elf64_Ehdr header;

    if (argc != 2)
    {
        print_error("Usage: elf_header elf_filename");
        exit(98);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        print_error("Error: Cannot read from file");
        exit(98);
    }

    read_bytes = read(fd, &header, sizeof(header));
    if (read_bytes < (int)sizeof(header))
    {
        print_error("Error: Cannot read from file");
        close(fd);
        exit(98);
    }

    if (header.e_ident[EI_MAG0] != ELFMAG0 ||
        header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 ||
        header.e_ident[EI_MAG3] != ELFMAG3)
    {
        print_error("Error: Not an ELF file");
        close(fd);
        exit(98);
    }

    print_elf_header(header);

    close(fd);
    return (0);
}

