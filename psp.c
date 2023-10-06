#include <stack.h>
#include <stdio.h>


int main()
{
    t_stack *stck;
    int n;
    scanf("%d", &n);
    char arr[n];
    scanf("%s", &arr);
    stack_char_importer(arr, n, stck);
    stack_foreach(*stck, printf);
}