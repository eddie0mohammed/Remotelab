#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int g_count = 0;

char    *b_base(unsigned long num, int base)
{
        char            *ref;
        static char     buffer[15];
        char            *ptr;

        ref = "0123456789abcdef";
        ptr = &buffer[14];
        *ptr = '\0';
        if (!num)
                *ptr = '0';
        while (num)
        {
                *--ptr = ref[num % base];
                num /= base;
        }
        return (ptr);
}

int             b_print(char *s)
{
        int     count;

        count = 0;
        if (s == NULL)
        {
                b_print("(null)");
                return (-1);
        }
        while (s[count])
                count++;
        write(1, s, count);
        g_count += count;
        return (count);
}

void    b_putchar(int c)
{
        write(1, &c, 1);
        g_count++;
}

void    ft_putnbr(int num)
{
        if (num == -2147483648)
                b_print("-2147483648");
        else
        {
                if (num < 0)
                {
                        b_putchar('-');
                        num = -num;
                }
                if (num >= 10)
                        ft_putnbr(num / 10);
                b_putchar((num % 10) + '0');
        }
}

int             b_printf(const char *restrict fmt, ...)
{
        va_list                 ap;

        g_count = 0;
        va_start(ap, fmt);
        while (*fmt)
        {
                if (*fmt != '%')
                        b_putchar(*fmt);
                else if (*++fmt == 'd' || *fmt == 'i' || *fmt == 'u')
                        (*fmt != 'u') ? ft_putnbr(va_arg(ap, int)) : \
                                                b_print(b_base(va_arg(ap, unsigned int), 10));
                else if (*fmt == 'c' || *fmt == '%')
                        (*fmt != '%') ? b_putchar((va_arg(ap, int))) : b_putchar('%');
                else if (*fmt == 'o' || *fmt == 'x')
                        b_print(b_base(va_arg(ap, unsigned int), (*fmt == 'o') ? 8 : 16));
                else if (*fmt == 'p')
                        b_print("0x") && b_print(b_base(va_arg(ap, unsigned long), 16));
                else if (*fmt == 's')
                        b_print(va_arg(ap, char *));
                fmt++;
        }
        va_end(ap);
        return (g_count);
}

int     main(void)
{
        char                    *a = NULL;
        char                    b[] = "hey there,";
        char                    c[] = "this is a trial version!!!...";
        char                    d = '\0';
        char                    e = 'b';
        int                     f = -1;
        int                     g = -23;
        int                     h = 123;
        int                     i = -100;
        unsigned int            ui = -10;
        int                     xx = 100;
        
        int aaa = b_printf("aloha, %s %s %s %c %c %i %d %o %x %u\n%p\n",\
                        a, b, c, d, e, f, g, h, i, ui, &xx);
        int bbb = printf("aloha, %s %s %s %c %c %i %d %o %x %u\n%p\n",\
                        a, b, c, d, e, f, g, h, i, ui, &xx);

        printf("\n\n\n%d, %d \n", aaa, bbb);
        return (0);
}