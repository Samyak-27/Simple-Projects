#include<stdio.h>
#include<math.h>

int main(void){
    int numImg_1;
    int numImg_2;
    int numRel_1;
    int numRel_2;
    char img_1;
    char img_2;
    char operand_1;
    char operand_2;
    int calc_1;
    int calc_2;

    //user inputs

    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d %c %c %d", &numImg_1, &img_1, &operand_1, &numRel_1);
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d %c %c %d", &numImg_2, &img_2, &operand_2, &numRel_2);

    //Calculations

    calc_1 = ((numImg_1*numImg_2)*-1) + (numRel_1*numRel_2);
    calc_2 = (numImg_1 * numRel_2) + (numImg_2 * numRel_1);

    printf("(%d %c %c %d) *", numImg_1, img_1, operand_1, numRel_1);
    printf(" (%d %c %c %d) = ", numImg_2, img_2, operand_2, numRel_2);
    printf("%di + %d \n", (int)calc_2, (int) calc_1);

    return 0;
}