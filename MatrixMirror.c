#include<stdio.h>
#define MAX 10

void matrixMirror(int input[][MAX], int total_size)
{
    int num_row = 0, num_col = 0, temp = 0, r = 0, c = 0;
    num_row = total_size/sizeof(input[0]);
    num_col = sizeof(input[0])/sizeof(int); 
    
    for( r = 0; r < num_row ; r++)
    {
        for( c = 0; c < num_col/2 ; c++)
        {            
            temp = bitwise_mirror(input[r][c]);
            input[r][c] = bitwise_mirror(input[r][num_col - c - 1] );
            input[r][num_col - c - 1] = temp;               
        }   
        
        if(num % 2 != 0)
        {
            input[r][c] = bitwise_mirror(input[r][c]);
        }
    }    
}

void printMatrix(int input[][MAX], int totalsize)
{
    int num_row = 0, num_col = 0;
    num_row = totalsize / sizeof(input[0]);
    num_col = sizeof(input[0]) / sizeof(input[0][0]);  
    
    for( int r = 0; r < num_row ; r++)
    {
        printf("\n");
        for( int c = 0; c < num_col ; c++)
        {
            printf("%x ", input[r][c]);
                   
        }          
    }    
}

int bitwise_mirror(int val)
{
    int num_of_bits = sizeof(val) * 8;
    
    int int_mask = ~(0);
    int final_msb = 0, final_lsb = 0, mask = 0;
    for( int i = 0; i < num_of_bits / 2 ; i++)
    {
        mask = int_mask & (~((uint)0x1 << i)) & (~((uint)0x1 << (num_of_bits - 1 - i)));
        final_msb = ((uint)(val >> i) & 0x1) << (num_of_bits - 1 - i);
        final_lsb = (((uint)val >> (num_of_bits - 1 - i)) & 0x1) << i;
        val = (val & mask) | final_msb | final_lsb;
        
    }
    
    return val;
    
}
int main() {
    
    int input[3][3] = {{1, 2, 3},\
                            {4, 5, 6},\
                            {7, 8, 9}};
    
    printMatrix(input, sizeof(input));
    matrixMirror(input, sizeof(input));
    printMatrix(input, sizeof(input));
    
}