#include<stdio_ext.h>  //sindhu changes.
#include<stdlib.h>
#include<string.h>
#define R 4
#define C 4
int base1[R][C], base2[R][C], base3[R][C];
int vehicle_number = 0;
void basement1();
void basement2(int temp);
void basement3();
void display();
void availabilities(int base[R][C],int r, int c);
int rearrangement(int rebase[R][C],int r, int c, int n);
void main()
{
	int opt,subopt;
	int select_basement;
	while(1)
	{
		printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\nMENU:\n\t1.Entry\n\t2.Clear all vehicles\n\t3.Display Basements\n\t4.Exit\n");
		printf("\nEnter the option:");
		__fpurge(stdin);
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:printf("\nEnter the type of vehicle (if 2W enter 2, if 4W enter 4):");
wheels:			       scanf("%d",&subopt);
			       if(subopt==2)
			       {
				       printf("\nYour token number is : %d\n", ++vehicle_number);
				       basement1();
			       }
			       else if(subopt==4)
			       {
				       printf("\nYour token number is : %d\n", ++vehicle_number);
				       basement3();
			       }
			       else
			       {
				       printf("\nKindly select either 2 or 4 only\n :");
				       goto wheels;
			       }
			       break;
			case 2:printf("\nThis option is not available\n");
			       break;
			case 3:printf("\nSelect basement 1/2/3:");
basement_options: scanf("%d",&select_basement);
			       if(select_basement == 1)
				       display(base1);
			       else if(select_basement == 2)
				       display(base2);
			       else if(select_basement == 3)
				       display(base3);
			       else
			       {
				       printf("\nGiven basement is incorrect, Kindly give correct basement number:");
				       goto basement_options;
			       }
			       break;
			case 4:exit(0);
			default:printf("\nInvalid option\n");
		}
	}
}
void basement1()
{
	int i,j;
	int r1,c1;
	int ret = 0;
	int count = 0;
	if(count == 0)
	{
		printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\nThese are the availabilities in basement 1\n");
availabilities_base1:		for(i=0;i<R;i++)
				{
					for(j=0;j<C;j++)
					{
						if(base1[i][j]==0)
						{
							printf("%d%d ",i,j);
							count ++;
						}
						else
							printf(" F ");
					}
					printf("\n");
				}
				if(count != 0)
				{
					printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("\nChoose the slot:");
					scanf("%d%d",&r1,&c1);
					if((r1 < 0) || (r1 > 3) || (c1 < 0) || (c1 > 3))
					{
						printf("\nKindly select the available slots only\n");
						goto availabilities_base1;
					}
					if(r1 != 0 && r1 != 3 && c1 != 0 && c1 != 3)
					{
						ret = rearrangement(base1,r1,c1,vehicle_number);
						if(ret == 1)
						{
							printf("\nAnd also here are all available slots\n");
							goto availabilities_base1;
						}
					}
					else
					{
						if(base1[r1][c1] == 0)
						{
							base1[r1][c1] = vehicle_number;
							printf("\nSuccessfully parked\n");
							count = 0;
							return;
						}
						else
						{
							availabilities(base1,r1,c1);
							printf("\nAnd also here are all available slots\n");
							count = 0;
							goto availabilities_base1;
						}
					}
				}
				else if(count == 0)
				{
					printf("\nBasement 1 is full\nGo to Basement 2\n");
					basement2(vehicle_number);
				}
	}
}
void basement2(int temp)
{
	int i,j;
	int r2,c2;
	int ret = 0;
	int count = 0;
	if(count == 0)
	{
		printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\nThese are the availabilities in basement 2\n");
availabilities_base2:		for(i=0;i<R;i++)
				{
					for(j=0;j<C;j++)
					{
						if(base2[i][j]==0)
						{
							printf("%d%d ",i,j);
							count ++;
						}
						else
							printf(" F ");
					}
					printf("\n");
				}
				if(count != 0)
				{
					printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("\nChoose the slot:");
					scanf("%d%d",&r2,&c2);
					if((r2 < 0) || (r2 > 3) || (c2 < 0) || (c2 > 3))
					{
						printf("\nKindly select the available slots only\n");
						goto availabilities_base2;
					}
					if(r2 != 0 && r2 != 3 && c2 != 0 && c2 != 3)
					{
						rearrangement(base2,r2,c2,temp);
						if(ret == 1)
						{
							printf("\nAnd also here are all available slots\n");
							goto availabilities_base2;
						}
					}
					else
					{
						if((base2[r2][c2] == 0))
						{
							base2[r2][c2] = temp;
							printf("\nSuccessfully parked\n");
							count = 0;
							return;
						}
						else
						{
							availabilities(base2,r2,c2);
							printf("\nAnd also here are all available slots\n");
							count = 0;
							goto availabilities_base2;
						}
					}
				}
				else if(count == 0)
				{
					printf("\nBasement 2 is full\nThere is no parking space\n");
				}
	}
}
void basement3()
{
	int i,j;
	int ret;
	int r3,c3;
	int count = 0;
	if(count == 0)
	{
		printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\nThese are the availabilities in basement 3\n");
availabilities_base3:		for(i=0;i<R;i++)
				{
					for(j=0;j<C;j++)
					{
						if(base2[i][j]==0)
						{
							printf("%d%d ",i,j);
							count ++;
						}
						else
							printf(" F ");
					}
					printf("\n");
				}
				if(count != 0)
				{
					printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
					printf("\nChoose the slot:");
					scanf("%d%d",&r3,&c3);
					if((r3 < 0) || (r3 > 3) || (c3 < 0) || (c3 > 3))
					{
						printf("\nKindly select the available slots only\n");
						goto availabilities_base3;
					}
					if(r3 != 0 && r3 != 3 && c3 != 0 && c3 != 3)
					{
						ret = rearrangement(base3,r3,c3,vehicle_number);
						if(ret == 1)
						{
							printf("\nAnd also here are all available slots\n");
							goto availabilities_base3;
						}
					}
					else
					{
						if((base3[r3][c3] == 0))
						{
							base3[r3][c3] = vehicle_number;
							printf("\nSuccessfully parked\n");
							count = 0;
							return;
						}
						else
						{
							availabilities(base3,r3,c3);
							printf("\nAnd also here are all available slots\n");
							count = 0;
							goto availabilities_base3;
						}
					}
				}
				else if(count == 0)
				{
					printf("\nBasement 3 is full\nGo to Basement 2\n");
					basement2(vehicle_number);
				}
	}
}
int rearrangement(int rebase[R][C],int r, int c, int n)
{
	int i,j;
	int count = 0;
	int recount_c = 0;
	int recount_r = 0;
	if(rebase[r][c] != 0)
	{
		availabilities(rebase,r,c);
		return 1;
	}
	for(i=0;i<C;i++)
	{
		if(rebase[r][i] != 0)
			recount_c++;
	}
	if(recount_c <= 1)
	{
		rebase[r][c] = n;
		printf("\nSuccessfully parked\n");
		return 0;
	}
	else if(recount_c > 1)
	{
		if(((rebase[r][c-1] == 1)&&((c-1) == 0)) || ((rebase[r][c+1] == 1)&&((c+1) == 3)))
		{
			if((rebase[r][c-1] == 0) && ((c-1) == 0))
			{
				rebase[r][c] = n;
				printf("\nSuccessfully parked\n");
				return 0;
			}
			else if((rebase[r][c+1] == 0) && ((c+1) == 3))
			{
				rebase[r][c] = n;
				printf("\nSuccessfully parked\n");
				return 0;
			}
		}
		for(i=0;i<R;i++)
		{
			if(rebase[i][c] != 0)
				recount_r++;
		}
		if(recount_r <= 1)
		{
			rebase[r][c] = n;
			printf("\nSuccessfully parked\n");
			return 0;
		}
		else if(recount_r > 1)
		{
			if((rebase[r-1][c] != 0) && ((r-1) == 0))
			{
				rebase[r][c] = rebase[r-1][c];
				rebase[r-1][c] = n;
				printf("\nYour vehicle is parked successfully at the location %d%d\n",r-1,c);
				return 0;
			}
			else if((rebase[r+1][c] != 0) && ((r+1) == 3))
			{
				rebase[r][c] = rebase[r+1][c];
				rebase[r+1][c] = n;
				printf("\nYour vehicle is parked successfully at the location %d%d\n",r+1,c);
				return 0;
			}
		}
	}
}
void display(int basement[R][C])
{
	int i,j;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("%d ",basement[i][j]);
		}
		printf("\n");
	}
}
void availabilities(int base[R][C],int r, int c)
{
	if((base[r][c] != 0))
	{ 
		printf("\nThe slot you have choosed is not empty, These are the slots available near them, Kindly select one\n");
		if((r == 0) || (r == 3) && (c == 0) || (c == 3))
		{
			if((r == 0) && (c == 0))
			{
				if(base[r][c+1] == 0)
					printf("%d%d ",r,c+1);
				if(base[r+1][c] == 0)
					printf("%d%d ",r+1,c);
			}
			else if((r == 0) && (c == 3))
			{
				if(base[r][c-1] == 0)
					printf("%d%d ",r,c-1);
				if(base1[r+1][c] == 0)
					printf("%d%d ",r+1,c);
			}
			else if((r == 3) && (c == 0))
			{
				if(base[r-1][c] == 0)
					printf("%d%d ",r-1,c);
				if(base[r][c+1] == 0)
					printf("%d%d ",r,c+1);
			}
			else if((r == 3) && (c == 3))
			{
				if(base[r][c-1] == 0)
					printf("%d%d ",r,c-1);
				if(base[r-1][c] == 0)
					printf("%d%d ",r-1,c);
			}
			else if((r == 0) && (c != 3) && (c != 0))
			{
				if(base[r][c+1] == 0)
					printf("%d%d ",r,c+1);
				if(base[r][c-1] == 0)
					printf("%d%d ",r,c-1);
				if(base[r+1][c] == 0)
					printf("%d%d ",r+1,c);
			}
			else if((r == 3) && (c != 0) && (c != 3))
			{
				if(base[r][c+1] == 0)
					printf("%d%d ",r,c+1);
				if(base[r][c-1] == 0)
					printf("%d%d ",r,c-1);
				if(base[r-1][c] == 0)
					printf("%d%d ",r-1,c);
			}
			else if((c == 0) && (r != 3) && (r != 0))
			{
				if(base[r+1][c] == 0)
					printf("%d%d ",r+1,c);
				if(base[r-1][c] == 0)
					printf("%d%d ",r-1,c);
				if(base[r][c+1] == 0)
					printf("%d%d ",r,c+1);
			}
			else if((c == 3) && (r != 0) && (r != 3))
			{
				if(base[r+1][c] == 0)
					printf("%d%d ",r+1,c);
				if(base[r-1][c] == 0)
					printf("%d%d ",r-1,c);
				if(base[r][c-1] == 0)
					printf("%d%d ",r,c-1);
			}
		}
		else
		{
			if(base[r][c+1] == 0)
				printf("%d%d ",r,c+1);
			if(base[r][c-1] == 0)
				printf("%d%d ",r,c-1);
			if(base[r+1][c] == 0)
				printf("%d%d ",r+1,c);
			if(base[r-1][c] == 0)
				printf("%d%d ",r-1,c);
		}
		printf("\n");
	}
}
