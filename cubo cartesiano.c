//El siguiente programa te permite observar la forma como los datos se almacenan con respecto a su ubicación real en el cubo cartesiano

#include<stdio.h>
int main()
{
   int i, j, k;
   int arr[3][4][2] = {
      { {2, 4}, {7, 8}, {3, 4}, {5, 6} },
      { {7, 6}, {3, 4}, {5, 3}, {2, 3} },
      { {8, 9}, {7, 2}, {3, 4}, {5, 1} }
      };
   for(i=2; i>=0; i--)
   {
      for(j=0; j<4; j++)
      {
         for(k=0; k<1; k++)
            printf("arr[%d][%d][%d] = %d  ", i, j, k, arr[i][j][k]);
         printf("\t");
      }
      printf("\n");
   }
   return 0;
}


