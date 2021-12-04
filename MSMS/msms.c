#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>

int i;

int getcust_id();
int getsupp_id();

void welcome();
void main_menu();


void bill();

void about();

void medicine();
void medi_sale();
void stock();
void update_stock();
void medi_entry();
void medi_search();
void remain();

void supplier();
void supp_entry();
void supp_list();
void sup_update();
void search();
void search_id();
void search_name();

void customer();
void cust_search();
void search_cid();
void search_cname();
void cust_entry();
void cust_list();
void cust_update();

void report_menu();
void report();
void sale_rpt();
void sale_rpt_daily();
void profit_rpt();
void pur_rpt();
void pur_rpt_daily();

struct medical
{
	char id[6];
	char medi_name[20];
	int rack;
	char cabnit[2];
	int quantity;
	float sale;
	float total;
	float unit;
	float cost;
	float profit;
	float bye;
	int qty;
	char pur_date[15];
	char exp_date[15];
	char manu_date[15];
	int bill_no;
	char comp_name[20];
	char supp_name[30];
};

struct medical temp;
struct medical x[20];
FILE* ptr;

char a[10];
struct supplier
{
	int supp_id;
	char supp_name[25];
	char city[20];
	char mob_no[11];
	char email[30];

};
struct supplier temp1;

struct customer
{
	int cust_id;
	char cust_name[30];
	char city[20];
	char mob_no[11];
	char email[50];

};
struct customer temp_c;
FILE* ptr1;

struct bill
{
	char billno[6];
	char cname[30];
	char mediname[30];
	int medi_qty;
	float medi_rate;
	float total;
	int day;
	int month;
	int year;

};
struct bill bil;
FILE* ptrbill;
struct sales_report
{
	char medi_id[6];
	char medir_name[20];
	char cust_name[30];
	int sDay, sMonth, sYear;
	int qty;
	float rate;
	float total;
};
struct sales_report s_r;
FILE* ptrs_r;

struct purchase_report
{
	char medi_id[6];
	char medir_name[20];
	char supp_name[30];
	int sDay, sMonth, sYear;
	int qty;
	float rate;
	float total;
};
struct purchase_report p_r;
FILE* ptrp_r;

struct profit_report
{
	char medi_id[6];
	char medir_name[20];
	int sDay, sMonth, sYear;
	int qty;
	float rate;
	float unit;
	float profit;
};
struct profit_report pr_r;
FILE* ptrpr_r;

void linkfloat()
{
	float f, * p;
	p = &f;
	f = *p;
}

int t(void)
{

	time_t t = time(0);    	
	struct tm* now = localtime(&t);

 	printf("Date: %d-%d-%d ", now->tm_mday, now->tm_mon, now->tm_year);
 	printf("Time: %d:%d:%d", now->tm_hour, now->tm_min, now->tm_sec);
	return 0;
}

void ventry(char t[], int code)
{
	int i = 0;
	if (code == 0)
	{
		while ((t[i] = getch()) != '\r' && i < 30)
			if ((t[i] >= 97 && t[i] <= 122) || (t[i] >= 65 && t[i] <= 90) || t[i] == 32 || t[i] == '_')
			{
				printf("%c", t[i]);
				i++;
			}
			else if (t[i] == 8 && i > 0)
			{
				printf("%c%c%c", 8, 32, 8);
				i--;               
			}
	}
	else if (code == 1)
	{
		while ((t[i] = getch()) != '\r' && i < 10)
			if ((t[i] >= 48 && t[i] <= 57) || t[i] == 46 || t[i] == '-')
			{
				printf("%c", t[i]);
				i++;
			}
			else if (t[i] == 8 && i > 0)
			{
				printf("%c%c%c", 8, 32, 8);
				i--;               
			}
	}
	else if (code == 2)
	{
		while ((t[i] = getch()) != '\r' && i < 30)
			if ((t[i] >= 97 && t[i] <= 122) || (t[i] >= 65 && t[i] <= 90) || (t[i] >= 48 && t[i] <= 57) || t[i] == 32 || t[i] == 8 || t[i] == '@' || t[i] == '.')
			{
				printf("%c", t[i]);
				i++;
			}
			else if (t[i] == 8 && i > 0)
			{
				printf("%c%c%c", 8, 32, 8);
				i--;               
			}
	}

	t[i] = '\0';
}

int getsupp_id()
{

	FILE* fp;
	fp = fopen("supplier.dat", "r");
	if (fp == NULL)
	{
 		printf("Data not Found.....");
		getch();
 	}
	else
	{
		temp1.supp_id = 100;
		rewind(fp);
		while (fscanf(fp, "%d %s %s %s %s", &temp1.supp_id, temp1.supp_name, temp1.city, temp1.mob_no, temp1.email) != EOF)
		{
		}
	}
	fclose(fp);
	return temp1.supp_id + 1;
}

int getcust_id()
{
	FILE* fp;
	fp = fopen("customer.dat", "r");
	if (fp == NULL)
	{
 		printf("Data not Found.....");
		getch();
 	}
	else
	{
		temp_c.cust_id = 100;
		rewind(fp);
		while (fscanf(fp, "%d %s %s %s %s", &temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email) != EOF)
		{
		}
	}
	fclose(fp);
	return temp_c.cust_id + 1;
}

void welcome()
{
	int j, k, l, m;
	system("cls");
	for (m = 0; m < 16; m++)
	{
		for (i = 0; i < 16; i++)
		{
			printf("WELCOME");
			k = i + 2;
			printf("TO");
			l = i + 3;
		  	printf("MEDICAL");
		  	printf("STORE");
		  	printf("SYSTEM");
 			j = i + 1;
		 	printf("Loading......");
		}
	}
}


int main()
{
	char name[15];
	char pass[15];
	int count = 0, i;

	system("cls");
	main_menu();
	 
}

void main_menu()
{
	char ch;

	do
	{
		system("cls");
		printf("Supplier Info\n");
		printf("Customer Info\n");
		printf("Medicine\n");
		printf("Report\n");
		printf("Bill\n");
		printf("About\n");
		printf("Exit\n\n");
		t();
		printf("\n\nWelcome To Medical Store\n");
 		 
		remain();
		printf("\nPress ");
 		printf("First Character for further Menu ");

		ch = toupper(getche());
		switch (ch)
		{
		case 'S':supplier();
			break;
		case 'C':customer();
			break;
		case 'M':medicine();
			break;
		case 'R':report_menu();
			break;
		case 'B':bill();
			break;
		case 'A':about();
			break;
		case 'E': 			 			
			printf("\n\nDo you want to exit now? Y/N :");
			ch = (getche());
			ch = toupper(ch);
			if (ch == 'Y')
			{
 				system("cls");
				  				printf(" Please wait.....");
				 				exit(0);
			}
			else
			{
				main_menu();
			}

		default:  			
			printf("\n\nPlease Enter right character ONLY (S,C,M,R,B,A).");
			getch();
 		}
	} while (ch != 'E');
}
 void supplier()
{
	char ch;
	do
	{
		system("cls");
 		printf("----------------");
 		printf("Supplier MENU");
 		printf("----------------\n\n");
 		printf("A");
 		printf("dd New Supplier\n");

 		printf("U");
 		printf("pdate Supplier\n");

 		printf("S");
 		printf("earch Supplier\n");

 		printf("L");
 		printf("ist of Existing Supplier\n\n");

 		printf("M");
 		printf("ain Menu\n");
 
 		printf("\nPress First Character for further Operation ");

		ch = toupper(getche());
		switch (ch)
		{
		case 'A': 			supp_entry();
			break;
		case 'U': 			sup_update();
			break;
		case 'L': 			supp_list();
			break;
		case 'S':search();
			break;
		case 'M':main_menu();
			break;
		default:  			
			printf("\n\nPlease Enter right character ONLY (A,U,L,S,M).");
			getch();
 		}
	} while (ch != 'M');

}
 void customer()
{
	char ch;
	do
	{
		system("cls");

 		printf("---------------");
 		printf("Customer Menu.");
 		printf("---------------\n\n");
 		printf("A");
 		printf("dd New Customer\n");

 		printf("U");
 		printf("pdate Customer\n");

 		printf("S");
 		printf("earch Customer\n");

 		printf("L");
 		printf("ist of Existing Customer\n\n");

 		printf("M");
 		printf("ain Menu\n");
 
 		printf("\n\nPress First Character for further Operations  ");

		ch = toupper(getche());
		switch (ch)
		{
		case 'A': 			cust_entry();
			break;
		case 'U': 			cust_update();
			break;
		case 'L': 			cust_list();
			break;
		case 'S':cust_search();
			break;
		case 'M':main_menu();
			break;
		default:  			
			printf("\n\nPlease Enter right character ONLY (A,U,L,S,M). ");
			getch();
 		}
	} while (ch != 'M');

}
 void medicine()
{
	char ch;
	do
	{
		system("cls");

 		printf("---------------");
 		printf("Medicine Menu.");
 		printf("---------------\n\n");
 		printf("P");
 		printf("urchase New Medicine\n");

 		printf("S");
 		printf("ale Medicine\n");

 		printf("Sto");
 		printf("c");
 		printf("k of Medicine\n");

 		printf("Se");
 		printf("a");
 		printf("rch Medicine\n\n");

 		printf("M");
 		printf("ain Menu\n");
 
 		printf("\n\nPress First Character for further Operations  ");

		ch = toupper(getche());
		switch (ch)
		{
		case 'P':medi_entry();
			break;
		case 'S':medi_sale();
			break;
		case 'C':stock();
			break;
		case 'A':medi_search();
			break;
		case 'M':main_menu();
			break;
		default:  			
			printf("\n\nPlease Enter right character ONLY (P,S,C,M).");
			getch();
 		}
	} while (ch != 'M');

}
 void report_menu()
{
	char ch;
	do
	{
		system("cls");

 		printf("---------------");
 		printf("Report Menu.");
 		printf("---------------\n\n");
 		printf("P");
 		printf("urchase Report\n");

 		printf("S");
 		printf("ale Report\n");

 		printf("Pr");
 		printf("o");
 		printf("fit Report\n");

 		printf("D");
 		printf("a");
 		printf("ily Sale Report\n");

 		printf("D");
 		printf("aily Purchase Report\n\n");

 		printf("M");
 		printf("ain Menu\n");
 
 		printf("\n\nPress First Character for further Operations  ");

		ch = toupper(getche());
		switch (ch)
		{
		case 'P':pur_rpt();
			break;
		case 'S':sale_rpt();
			break;
		case 'A':sale_rpt_daily();
			break;
		case 'O':profit_rpt();
			break;
		case 'D':pur_rpt_daily();
			break;
		case 'M':main_menu();
			break;
		default:  			
			printf("\n\nPlease Enter right character ONLY (P,S,O,M).");
			getch();
 		}
	} while (ch != 'M');

}

void about()
{
	int c;
	system("cls");

	do
	{
		 
			  		 		printf("***** MEDICAL STORE *****\n\n");
 		printf("=> This Project Is About Medical Store \n");
 		printf("=> In This Project we Can Add Medicine ,Customer,Supplier Details\n");
 		printf("=> We Can Modifed & Delete Existing Record\n");
 		printf("=> We Can Also Search Medicine ,Customer,Supplier Details\n");
 		printf("=> It's Helpfull For Display Stock Of Medicine\n");

		printf("\n<<<<-Press 1 for main menu->>>>\n");
		c = (getche());

		switch (c)
		{
			case '1': 			
				main_menu();
 				puts("<<--ENTER FROM 1 PLEASE-->>");
				getch();
		}

	} while (c != '1');

}
 void remain()
{
	ptr1 = fopen("medical.dat", "r");
	if (ptr1 == NULL)
	{
		printf("\n\t Can not open File medical.dat! Create it !! ");
	}
	while ((fread(&temp, sizeof(temp), 1, ptr1)) == 1)
	{
		if (temp.quantity < 10)
		{
 			printf("%s : ", temp.medi_name);
			printf("\nQuantity of this medicine is less then 10\n");
		}
	}
}

 void bill()
{
	time_t td = time(0);    	
	struct tm* now = localtime(&td);

	FILE* ptrbill;
	char id[6];
	int j = 1, d1, m, y, k;
	float netamt = 0.0;
	d1 = now->tm_mday;
	m = now->tm_mon;
	y = now->tm_year;
	system("cls");
	ptrbill = fopen("dbbill.dat", "r");
 	printf("\nEnter bill no : ");
	scanf("%s", &id);
	system("cls");
 	printf("\nBill No: ");
	printf(" %s", id);
 	printf("\nCustomer Name: ");
 	printf("\nDate : ");
	printf("%d-%d-%d", d1, m, y);
 	printf("\nSr.No   Medicine Name       Qty          Rate         Total ");
 	printf("---------------------------------------------------------------------");

	i = 15;
	while (fscanf(ptrbill, "%s %s %s %d %f %f %d %d %d", bil.billno, bil.cname, bil.mediname, &bil.medi_qty, &bil.medi_rate, &bil.total, &bil.day, &bil.month, &bil.year) != EOF)
	{

		do
		{
			if (strcmp(id, bil.billno) == 0)
			{
 				printf(" %d", j);
 				printf(" %s", bil.mediname);
 				printf(" %s", bil.cname);
 				printf(" %d", bil.medi_qty);
 				printf(" %.2f", bil.medi_rate);
 				printf(" %.2f", bil.total);
				netamt = netamt + bil.total;
				i++;
				j++;
 				printf("                                ");
 				printf("\n\nPress Any key to go to  MENU ...........\n\n");

				 			}

		} while (feof(ptrbill));

	}

 	printf("---------------------------------------------------------------------");
 	printf("Net Amount : ");
	printf("%.2f", netamt);

	fclose(ptrbill);
	getch();
 }

 void supp_entry()
{
	int id;
	char ch;
	FILE* fp;
	system("cls");

	fp = fopen("supplier.dat", "a");
	if (fp == NULL)
	{
		printf("\n Can not open file supplier.dat !! Create it !!");
		exit(0);
	}
	system("cls");
	ch = 'y';
	while (ch == 'y')
	{
		system("cls");
		t();
   		printf(" \nSUPPLIER ENTRY \n\n");
 		temp1.supp_id = getsupp_id();
		printf("SUPPLIER ID : %d ", temp1.supp_id);
		printf("\nSUPPLIER NAME : ");
		ventry(temp1.supp_name, 0);
 		printf("\nCITY        : ");
		ventry(temp1.city, 0);
 		printf("\nCONTACT NO.   : ");
		ventry(temp1.mob_no, 1);
 		printf("\nEMAIL ID    : ");
		gets(temp1.email);
		
		printf("\nS");
		printf("ave");
 		printf("\nC");
		printf("ancel");
 		printf("\n\nPress First charecter for the operation : ");
		ch = getch();
		if (ch == 's' || ch == 'S')
		{
			fprintf(fp, "%d %s %s %s %s\n\n", temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email);
			fprintf(fp, "\n");
			system("cls");
 			printf("\nSupplier Added successfully!!!!!\n");
			printf("\nMore entries  [y/n]");
			ch = getche();
		}
	}
	fclose(fp);

}
 void supp_list()
{
	char ch;
	int j;
	system("cls");
	ptr1 = fopen("supplier.dat", "r");
	if (ptr1 == NULL)
	{
		printf("\n\t Can not open File! ");
		exit(0);
	}
	system("cls");
 	t();
	printf("\n\nPress Anykey to go to SUPPLIER MENU !!!");
	printf("\n\n SUPPLIER LIST ");
	printf("\n\nID.  SUPPLIER NAME.      PH.NO.     CITY.         EMAIL");
 	i = 14;
	printf("\n=================================================================");
	while (fscanf(ptr1, "%d %s %s %s %s", &temp1.supp_id, temp1.supp_name, temp1.city, temp1.mob_no, temp1.email) != EOF)
	{
 		printf(" %d", temp1.supp_id);
 		printf(" %s", temp1.supp_name);
 		printf(" %s", temp1.city);
 		printf(" %s", temp1.mob_no);
 		printf(" %s", temp1.email);
		i = i + 2;
	}
	getche();
 }
 void search()
{
	int ch;

	do
	{
		system("cls");
		printf("\n\n Two options Available for searching \n");
 		printf("\nSearch by");
 		printf("I");
		printf("D number\n");

 		printf("\nSearch by");
 		printf("N");
		printf("ame\n");

 		printf("\nR");
		printf("eturn\n");
  		printf("\nPress First charecter for the operation : ");
		ch = toupper(getche());
		switch (ch)
		{
		case 'I':
 			search_id();
			break;
		case 'N':
 			search_name();
			break;
		case 'R':
 			supplier();
			break;
		default:
 			printf("\n\nYou entered wrong choice!!!!!\n");
			getch();
 		}
	} while (ch != 'R');

}
 void search_id()
{
	int id;
	FILE* fp;

	fp = fopen("supplier.dat", "r");
	if (fp == NULL)
	{
		printf("file can't open!!!!");

	}
	system("cls");
  	printf("\nEnter id to be searched:");
	scanf("%d", &id);
 	printf("\n\nPress Any key to Return Back Menu ....");
 	printf("ID.  SUPPLIER NAME.   CITY.     PH.NO.       EMAIL");
 	i = 18;
	printf("==============================================================");
	while (fscanf(fp, "%d %s %s %s %s", &temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email) != EOF)
	{
		if (temp1.supp_id == id)
		{
 			printf(" %d", temp1.supp_id);
 			printf(" %s", temp1.supp_name);
 			printf(" %s", temp1.city);
 			printf(" %s", temp1.mob_no);
 			printf(" %s", temp1.email);
			i++;
			break;
		}
	}
	if (temp1.supp_id != id)
	{
 		printf("\n\nRecord not found!");
	}
	fclose(fp);
	getche();
 }
 void search_name()
{
	char name[20];
	FILE* fp;

	fp = fopen("supplier.dat", "r");
	if (fp == NULL)
	{
		printf("\nfile can't open!!!!");

	}
	system("cls");
 	fp = fopen("supplier.dat", "rb");
 	printf("\n Enter Supplier Name to be searched : ");
	scanf("%s", &name);
 	printf("\n\nPress Any key to Return Back Menu ....");
 	printf("ID. SUPPLIER NAME.   CITY.     PH.NO.       EMAIL");
 	i = 18;
	printf("==============================================================");

	while (fscanf(fp, "%d %s %s %s %s", &temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email) != EOF)
	{
		if (strcmp(temp1.supp_name, name) == 0)
		{
 			printf(" %d", temp1.supp_id);
 			printf(" %s", temp1.supp_name);
 			printf(" %s", temp1.city);
 			printf(" %s", temp1.mob_no);
 			printf(" %s", temp1.email);
			i++;
			break;
		}
	}
	if (strcmp(temp1.supp_name, name) != 0)
	{
 		 		printf("\nRecord not found!!!\n");
	}
	fclose(ptr1);
	getche();
 }
 void sup_update()
{
	int i;
	char ch;
	int sid;
	FILE* ft;
	system("cls");
 	ptr1 = fopen("supplier.dat", "rb+");
	if (ptr1 == NULL)
	{
		printf("\n Can not open file!! ");
		exit(0);
	}
  	printf("\nModifying Supplier ");
 	printf("\nEnter supplier ID :  ");
	 	scanf("%d", &sid);
 
	ft = fopen("temp.dat", "w");
	if (ft == NULL)
	{
		printf("\n\nCannot open file temp.dat !! Create it !!!");
		exit(1);
	}
	else
	{
		while (fscanf(ptr1, "%d %s %s %s %s", &temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email) != EOF)
		{
			if (temp1.supp_id == sid)
			{
 				printf("\n\nExisting Record  \n\n");
 				printf("%d\t %s \t%s \t%s \t%s", temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email);
 				printf("\nEnter New Name       : ");
				ventry(temp1.supp_name, 0);
 				printf("\nEnter New mobile no  : ");
				ventry(temp1.mob_no, 1);
 				printf("\nEnter New City       : ");
				ventry(temp1.city, 0);
 				printf("\nEnter New email      : ");
				ventry(temp1.email, 2);
 				printf("\nU");
 				printf("pdate\t/\t");
 				printf("C");
 				printf("ancel\n");
 				printf("\nPress First charecter for the operation : ");
				ch = getch();
				if (ch == 'u' || ch == 'U')
				{
					fprintf(ft, "%d %s %s %s %s\n", temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email);
					printf("\n\nSupplier updated successfully...");
					remove("supplier.dat");
					rename("temp.dat", "supplier.dat");

				}
			}
			else
			{
				fprintf(ft, "%d %s %s %s %s\n", temp1.supp_id, temp1.supp_name, temp1.mob_no, temp1.city, temp1.email);
				fflush(stdin);
			}
		}

		fclose(ft);
		fclose(ptr1);
	}
}
  void cust_entry()
{
	char ch;
	int id;
	FILE* fp;
	system("cls");
	fp = fopen("customer.dat", "a");
	if (fp == NULL)
	{
		printf("\n Can not open file customer.dat !! Create it !!!");
		exit(0);
	}
	system("cls");
	ch = 'y';
	while (ch == 'y')
	{
		system("cls");
		t();
   		printf(" \n\nCUSTOMER ENTRY ");
 		temp_c.cust_id = getcust_id();
		printf("\n\nCUSTOMER ID :%d", temp_c.cust_id);
		printf("\nCUSTOMER NAME : ");
		ventry(temp_c.cust_name, 0);
 		printf("\nCITY        : ");
		ventry(temp_c.city, 0);
 		printf("\nCONTACT NO.   : ");
		ventry(temp_c.mob_no, 1);
 		printf("\nEMAIL ID    : ");
		gets(temp_c.email);

 		printf("\n\nS");
		printf("ave");
 		printf("C");
		printf("ancel\n");
 		printf("\nPress First charecter for the operation : ");
		ch = getch();
		if (ch == 's' || ch == 'S')
		{
			fprintf(fp, "%d %s %s %s %s\n", temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email);
			fprintf(fp, "\n");
			fflush(stdin);
			system("cls");
 			printf("\nCustomer Added Successfully!!!!!\n");
			printf("\nMore entries  [y/n] ");
			ch = getche();

		}
	}
	fclose(fp);
}

 void cust_list()
{
	char ch;
	system("cls");
	ptr1 = fopen("customer.dat", "r");
	if (ptr1 == NULL)
	{
		printf("\n\t Can not open File! ");
		exit(0);
	}
	system("cls");
 	  	printf("\nPress Anykey to go to CUSTOMER MENU!!!");
	   	printf(" \n\nCUSTOMER LIST ");
	 	i = 14;
 	printf(" \n\nID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
 	printf("==============================================================");
	while (fscanf(ptr1, "%d %s %s %s %s", &temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email) != EOF)
	{
 		printf(" %d", temp_c.cust_id);
 		printf(" %s", temp_c.cust_name);
 		printf(" %s", temp_c.city);
 		printf(" %s", temp_c.mob_no);
 		printf(" %s", temp_c.email);
		i = i + 2;
	}
	getche();
 }
 void cust_search()
{
	int ch;

	do
	{
		system("cls");
		printf(" \n\nTwo options Available for searching ");
 		printf("\n\nSearch by");
 		printf("I");
		printf("D number");

 		printf("\n\nSearch by");
 		printf("\nN");
		printf("ame");

 		printf("\n\nR");
		printf("eturn");
  		printf("\n\nPress First charecter for the operation : ");
		ch = toupper(getche());
		switch (ch)
		{
		case 'I':
 			search_cid();
			break;
		case 'N':
 			search_cname();
			break;
		case 'R':
 			customer();
			break;
		default:
 			printf("\nYou entered wrong choice!!!!!");
			getch();
 		}
	} while (ch != 'R');
	getche();
 }
 void search_cid()
{
	int id;
	system("cls");
 	ptr1 = fopen("customer.dat", "rb");
 	printf("\n\xDB\xDB\xB2  Enter id to be searched:");
	scanf("%d", &id);
	 	 	i = 18;
 	printf("\n\n ID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
 	printf("==============================================================");
	while (fscanf(ptr1, "%d %s %s %s %s", &temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email) != EOF)
	{
		if (temp_c.cust_id == id)
		{
 			printf(" %d", temp_c.cust_id);
 			printf(" %s", temp_c.cust_name);
 			printf(" %s", temp_c.city);
 			printf(" %s", temp_c.mob_no);
 			printf(" %s", temp_c.email);
 			 			printf("\n\nPress Any key to go to CUSTOMER MENU ...........");
			break;
		}
	}
	if (temp_c.cust_id != id)
	{
 		printf("\n\nRecord not found!");
	}
	fclose(ptr1);
	getche();
 }
/*****************************search by CUSTOMERname******************************/
void search_cname()
{
	char name[20];
	system("cls");
 	ptr1 = fopen("customer.dat", "rb");
 	printf("\n\n\xDB\xDB\xB2  Enter Customer Name to be searched:");
	scanf("%s", &name);
	i = 18;
 	printf("\n\n ID. CUSTOMER NAME.    CITY.     MOBILE.NO.      EMAIL");
 	printf("==============================================================");
	while (fscanf(ptr1, "%d %s %s %s %s", &temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email) != EOF)
	{
		if (strcmp(temp_c.cust_name, name) == 0)
		{
 			printf(" %d", temp_c.cust_id);
 			printf(" %s", temp_c.cust_name);
 			printf(" %s", temp_c.city);
 			printf(" %s", temp_c.mob_no);
 			printf(" %s", temp_c.email);
 			 			printf("\n\nPress Any key to go to CUSTOMER MENU ...........");
			break;
		}
	}
	if (strcmp(temp_c.cust_name, name) != 0)
	{
 		 		printf("\nRecord not found!");
	}
	fclose(ptr1);
	getche();
 }
 void cust_update()
{
	int i;
	char ch;
	int cid;
	FILE* ft;
	system("cls");
 	ptr1 = fopen("customer.dat", "rb+");
	if (ptr1 == NULL)
	{
		printf("\n Can not open file!! ");
		exit(0);
	}
  	printf("\n\n Modifying customer ");
 	printf("\n\nEnter the CUSTOMER ID : ");
	scanf("%d", &cid);
 
	ft = fopen("temp.txt", "w");
	if (ft == NULL)
	{
		printf("\n Can not open file");
		exit(0);
	}
	else
	{

		while (fscanf(ptr1, "%d %s %s %s %s", &temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email) != EOF)
		{
			if (temp_c.cust_id == cid)
			{
 				printf("\n\n*** Existing Record ***");
 				printf("%d\t %s \t%s \t%s \t%s", temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email);
 				printf("\nEnter New Name         : ");
				 				ventry(temp_c.cust_name, 0);
 				printf("\nEnter New mobile no    : ");
				 				ventry(temp_c.mob_no, 1);
 				printf("\nEnter New City         : ");
				 				ventry(temp_c.city, 0);
 				printf("\nEnter New email        : ");
				 				scanf("%s", temp_c.email);
 				 				printf("\n\nU");
 				 				printf("pdate");
 				 				printf("\n\nC");
 				 				printf("ancel");
 				printf("\n\nPress First charecter for the operation : ");
				ch = getche();
				if (ch == 'u' || ch == 'U')
				{
					fprintf(ft, "%d %s %s %s %s\n", temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email);
					 					fflush(stdin);
 					printf("\n\nCustomer updated successfully...");
					remove("customer.dat");
					rename("temp.txt", "customer.dat");
				}
			}
			else
			{
				fprintf(ft, "%d %s %s %s %s\n", temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email);
				fflush(stdin);
			}
		}

		fclose(ft);
		fclose(ptr1);
	}

}

  void medi_entry()
{
	char ch, id[6];
	 	time_t t = time(0);    	struct tm* now = localtime(&t);
	int f;
	FILE* fp;
	system("cls");
	 
	ptrp_r = fopen("purreport.dat", "a");
	ch = 'Y';
	while (ch == 'Y')
	{
		system("cls");
 		    		 		printf("\n\n MEDICINE PURSHASE  ");
		{
			  			printf("\nMEDICINE ID    : ");

 			ventry(temp.id, 1);
			strcpy(id, temp.id);

			printf("\nMEDICINE NAME  : ");

			fp = fopen("medical.dat", "r");
			while ((fread(&temp, sizeof(temp), 1, fp)) == 1)
			{

				if (strcmp(id, temp.id) == 0)
				{
					f = 1;
					break;
				}
			}
			fclose(fp);
			if (f == 1)
			{
 				printf("ID Allready Exists");
				getche();
 				system("cls");
				medi_entry();
			}
			else
			{
				ptr = fopen("medical.dat", "a+b");
				strcpy(temp.id, id);
				strcpy(p_r.medi_id, temp.id);
			}

 			ventry(temp.medi_name, 0);
			strcpy(p_r.medir_name, temp.medi_name);

			printf("\nENTER RACK NO  : ");

 			ventry(a, 1);
			temp.rack = atoi(a); 

			printf("\nCABNIT NO      : ");
 			ventry(temp.cabnit, 2);

			printf("\nCOMPANY NAME   : ");
 			ventry(temp.comp_name, 0);

			printf("\nSUPPLIER NAME  : ");
 			ventry(temp.supp_name, 0);
			strcpy(p_r.supp_name, temp.supp_name);

			printf("\nUNIT COST   Rs.:  ");
 			ventry(a, 1);
			temp.unit = atof(a);

			printf("\nSALE COST   Rs.: ");
			p_r.rate = temp.unit;
 			ventry(a, 1);
			temp.sale = atof(a);

			printf("\nQUANTITY       :  ");
 			ventry(a, 1);
			temp.quantity = atoi(a);
			p_r.qty = temp.quantity;

			printf("\nMFG.DATE(dd-mm-yyyy): ");
			ventry(temp.manu_date, 1);
 
			printf("\nEXP.DATE(dd-mm-yyyy): ");
			ventry(temp.exp_date, 1);

 			printf("==========================================================");
			temp.total = temp.quantity * temp.sale;

 			printf("\nTOTAL SALE COST = Rs. %.2f", temp.total);
			temp.cost = (temp.unit * temp.quantity);
 			printf("\nTOTAL UNIT COST = Rs. %.2f", temp.cost);
			p_r.total = temp.cost;
			p_r.sDay = now->tm_mday;
			p_r.sMonth = now->tm_mon;
			p_r.sYear = now->tm_year;
		}
 
		printf("\n\nS");

 		printf("ave");
 
		printf("\tC");

 		printf("ancel");
 		printf("\n\nPress First charecter for the operation : ");

		ch = toupper(getche());

		if (ch == 'S')
		{
			fwrite(&temp, sizeof(temp), 1, ptr);
			fflush(stdin);

			fprintf(ptrp_r, "%s %s %s %d %.2f %.2f %d %d %d\n", p_r.medi_id, p_r.medir_name, p_r.supp_name, p_r.qty, p_r.rate, p_r.total, p_r.sDay, p_r.sMonth, p_r.sYear);
			system("cls");
 			printf("\n\nMedicine Added sucessfully!!!!!!");
 			printf("\nMore entries  [y/n]");
			ch = toupper(getche());

		}

	}
	fclose(ptr);
	fclose(ptrp_r);
}

void medi_sale()
{
	struct bill bil;

	time_t t = time(0);
	struct tm* now = localtime(&t);
	int j, n, i, a, billno;
	int d1, m, y;
	float b, total, rate;
	char tar[30], ch, mediname[30], c_name[30], cname[30];
	FILE* fp, * fpc;
	int count = 0;

	d1 = now->tm_mday;
	m = now->tm_mon;
	y = now->tm_year;
	ch = 'y';
	while (ch == 'y')
	{
		fp = fopen("dbbill.dat", "a");
		ptr1 = fopen("customer.dat", "r");
		ptr = fopen("medical.dat", "r");
		ptrs_r = fopen("saleRpt.dat", "a");
		ptrpr_r = fopen("profitRpt.dat", "a");
		system("cls");
 		for (i = 3; i <= 45; i++)
		{
 			printf("%c", 219);
		}
		i = 9;
 		printf("\nCust_ID    Cust_Name");

		while (fscanf(ptr1, "%d %s %s %s %s", &temp_c.cust_id, temp_c.cust_name, temp_c.mob_no, temp_c.city, temp_c.email) != EOF)
		{
 			printf("%d", temp_c.cust_id);
 			printf("%s", temp_c.cust_name);
			i += 2;
		}

 		printf("ENTER MEDICINE ID TO BE SOLD  : ");
		ventry(tar, 1);

		j = 0;
		while ((fread(&temp, sizeof(temp), 1, ptr)) == 1)
		{
			if ((strcmp(temp.id, tar) < 0) || (strcmp(temp.id, tar) > 0))
			{
				x[j] = temp;
				j++;
			}
			else if ((strcmp(temp.id, tar) == 0))
			{

 				printf("\n Medicine Name        : %s", temp.medi_name);
 				printf("\n Quantity in stock    : %d", temp.quantity);
 				printf("\n Sales price          : %.2f", temp.sale);
 				printf("\n\nEnter bill number     : ");

				ventry(bil.billno, 1);

 				printf("Enter customer Name   : ");

				ventry(c_name, 0);

 				printf("Quantity want to sale : ");

				scanf("%d", &a);

				pr_r.profit = (temp.sale - temp.unit) * a;
				x[j] = temp;
				x[j].quantity = (x[j].quantity - a);
				x[j].total = (x[j].quantity * temp.sale);
				x[j].cost = (x[j].quantity * temp.unit);
				x[j].bye = (x[j].sale * a);
				b = x[j].bye;
				x[j].qty = a;
				j++;
				count++;
				strcpy(bil.cname, c_name);
				strcpy(s_r.cust_name, c_name);
				strcpy(bil.mediname, temp.medi_name);
				bil.medi_qty = a;
				bil.medi_rate = temp.sale;
				bil.total = temp.sale * a;

				bil.day = d1;
				bil.month = m;
				bil.year = y;

				fprintf(fp, "%s %s %s %d %.2f %.2f %d %d %d\n", bil.billno, bil.cname, bil.mediname, bil.medi_qty, bil.medi_rate, bil.total, bil.day, bil.month, bil.year);
				fflush(stdin);

				fclose(fp);

				s_r.sDay = d1;
				s_r.sMonth = m;
				s_r.sYear = y;
				strcpy(s_r.medi_id, tar);
				strcpy(s_r.medir_name, temp.medi_name);
				s_r.qty = a;
				s_r.rate = temp.sale;
				s_r.total = temp.sale * a;

				fprintf(ptrs_r, "%s %s %s %d %.2f %.2f %d %d %d\n", s_r.medi_id, s_r.medir_name, s_r.cust_name, s_r.qty, s_r.rate, s_r.total, s_r.sDay, s_r.sMonth, s_r.sYear);
				fflush(stdin);
				fclose(ptrs_r);

				pr_r.sDay = d1;
				pr_r.sMonth = m;
				pr_r.sYear = y;
				strcpy(pr_r.medi_id, tar);
				strcpy(pr_r.medir_name, temp.medi_name);
				pr_r.qty = a;
				pr_r.rate = temp.sale;
				pr_r.unit = temp.unit;
				fprintf(ptrpr_r, "%s %s %d %d %d %d %.2f %.2f  %.2f\n", pr_r.medi_id, pr_r.medir_name, d1, pr_r.sMonth, pr_r.sYear, pr_r.qty, pr_r.unit, pr_r.rate, pr_r.profit);
				fflush(stdin);
				fclose(ptrpr_r);

			}
		}
		if (count == 0)
		{
			system("cls");
 			printf("\n\nNot in stock!!!!!");
			getch();
 			return;
		}
		fclose(ptr1);
		fclose(ptr);
		n = j;
		system("cls");
		ptr = fopen("medical.dat", "wb");
		for (i = 0; i < n; i++)
			fwrite(&x[i], sizeof(x[i]), 1, ptr);
		fclose(ptr);
		system("cls");
  		printf("\n* Price paid by customer = %.2f", b);
 		printf("\n* Quantity sold          = %d", a);
		getch();
  		printf("\n\nMore enteries=(y/n) :");
		ch = getche();
	}

}

void stock()
{
	char ch;
	int i, c;
	do
	{
		system("cls");
		ptr1 = fopen("medical.dat", "r");
		if (ptr1 == NULL)
		{
			printf("\n Can not open File! ");
			exit(1);
		}
		system("cls");
  
 
		printf("\n\n STOCK OF MEDICINE ");

		i = 14;
 		printf("\n\nID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
 		printf("==================================================================\n");

		while ((fread(&temp, sizeof(temp), 1, ptr1)) == 1)
		{
 			printf(" %s", temp.id);
 			printf(" %s", temp.medi_name);
 			printf(" %d", temp.quantity);
 			printf(" %s", temp.supp_name);
 			printf(" %s", temp.exp_date);
			i++;
		}
 		printf("\n\nPress [1] for Update Medicine Stock  & [0] for main menu ");
		c = (getche());
		switch (c)
		{
		case '0': 			main_menu();
			break;
		case '1':update_stock();
			break;
		}

	} while (c != '1');
	getche();
 }

void medi_search()
{
	char mid[6];
	int i, c;
	system("cls");
	ptr1 = fopen("medical.dat", "r");
	if (ptr1 == NULL)
	{
		printf("\n Can not open File! ");
		exit(0);
	}
	system("cls");
 
 	printf("\n\nEnter Medicine Id to be searched : ");
	scanf("%s", &mid);
	system("cls");
  
 
	printf("\n\n MEDICINE ");

	i = 14;
 	printf("\n\nID.   MEDICINE NAME.    QTY     Supplier Name     Exp.Date");
 	printf("==================================================================\n");
	while ((fread(&temp, sizeof(temp), 1, ptr1)) == 1)
	{
		if (strcmp(mid, temp.id) == 0)
		{
 			printf(" %s", temp.id);
 			printf(" %s", temp.medi_name);
 			printf(" %d", temp.quantity);
 			printf(" %s", temp.supp_name);
 			printf(" %s", temp.exp_date);
			i++;
			break;
		}

	}
	if (strcmp(mid, temp.id) != 0)
	{
 		printf("\n\nNot in Stock.....");
	}
	getche();
}

void update_stock()
{
	char mid[6];
	int j, a, count = 0, n;
	system("cls");
	ptr = fopen("medical.dat", "rb");
	if (ptr == NULL)
	{
		printf("\n Can not open File! ");
		exit(0);
	}
	system("cls");
  	printf("\n\nPress Enter to go to MENU ...........");

 
	printf("\n\n UPDATE MEDICINE QUANTITY ");

 	printf("\n\nEnter medicine id to be update qty: ");
	scanf("%s", &mid);
	j = 0;

	while ((fread(&temp, sizeof(temp), 1, ptr)) == 1)
	{
		if ((strcmp(temp.id, mid) < 0) || (strcmp(temp.id, mid) > 0))
		{
			x[j] = temp;
			j++;
		}
		else
		{
 			printf("\nMedicine Name     : %s", temp.medi_name);
 			printf("\nQuantity in stock : %d", temp.quantity);
 			printf("\nQuantity want to update : ");
			scanf("%d", &a);
			x[j] = temp;
			x[j].quantity = (x[j].quantity + a);
			x[j].total = (x[j].quantity * temp.sale);
			x[j].cost = (x[j].quantity * temp.unit);
			x[j].bye = (x[j].sale * a);
			x[j].qty = a;
			j++;
			count++;
		}
	}
	if (count == 0)
	{
		system("cls");
 		printf("\n\nNot in stock!!!!!!");
		getch();
 		return;
	}
	fclose(ptr);
	n = j;
	system("cls");
	ptr = fopen("medical.dat", "wb");
	for (i = 0; i < n; i++)
		fwrite(&x[i], sizeof(x[i]), 1, ptr);
	fclose(ptr);
}

void sale_rpt()
{
	char ch;
	int j;
	system("cls");
	ptrs_r = fopen("saleRpt.dat", "r");
	if (ptrs_r == NULL)
	{
		printf("\n Can not open File! ");
		exit(0);
	}
	system("cls");
  	printf("\n\nPress any key to go to REPORT MENU ...........");
 
 
	printf("\n\nSales Report");

 	printf("\n\nID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
 	printf("===================================================================");
	j = 14;
	while (fscanf(ptrs_r, "%s %s %s %d %f %f %d %d %d\n", s_r.medi_id, s_r.medir_name, s_r.cust_name, &s_r.qty, &s_r.rate, &s_r.total, &s_r.sDay, &s_r.sMonth, &s_r.sYear) != EOF)
	{
 		printf("%s", s_r.medi_id);
 		printf("%s", s_r.medir_name);
 		printf("%s", s_r.cust_name);
 		printf("%d", s_r.qty);
 		printf("%.2f", s_r.rate);
 		printf("%.2f", s_r.total);
 		printf("%d-%d-%d", s_r.sDay, s_r.sMonth, s_r.sYear);
		j = j + 2;
	}
	getch();
 }

void pur_rpt()
{
	char ch;
	int j;
	system("cls");
	t();
 	ptrp_r = fopen("purreport.dat", "r");
	if (ptrp_r == NULL)
	{
		printf("\n\t Can not open File! ");
		exit(0);
	}
 	printf("\n\nPress Enter to go to REPORT MENU ...........");
 
 	printf("\n\nPurchase Report");

 	printf("\n\nID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
 	printf("===================================================================");
	j = 14;
	while (fscanf(ptrp_r, "%s %s %s %d %f %f %d %d %d\n", p_r.medi_id, p_r.medir_name, p_r.supp_name, &p_r.qty, &p_r.rate, &p_r.total, &p_r.sDay, &p_r.sMonth, &p_r.sYear) != EOF)
	{
 		printf("%s", p_r.medi_id);
 		printf("%s", p_r.medir_name);
 		printf("%s", p_r.supp_name);
 		printf("%d", p_r.qty);
 		printf("%.2f", p_r.rate);
 		printf("%.2f", p_r.total);
 		printf("%d-%d-%d", p_r.sDay, p_r.sMonth, p_r.sYear);
		j += 2;
	}
	getche();
 }
 void profit_rpt()
{
	char ch;
	int j;
	system("cls");
	t();
 	ptrpr_r = fopen("profitRpt.dat", "r");
	if (ptrpr_r == NULL)
	{
		printf("\n Can not open File! ");

	}
 	printf("\n\nPress Enter to go to REPORT MENU ...........");
 
 	printf("\n\nProfit Report");

 	printf("\n\nID. Medicine Name.   Date        Qty.  Unit Price  Sale Price. Profit. \n");
 	printf("===================================================================");
	j = 14;
	while (fscanf(ptrpr_r, "%s %s %d %d %d %d %f %f %f \n", pr_r.medi_id, pr_r.medir_name, &pr_r.sDay, &pr_r.sMonth, &pr_r.sYear, &pr_r.qty, &pr_r.unit, &pr_r.rate, &pr_r.profit) != EOF)
	{
 
		printf("%s", pr_r.medi_id);
 		printf("%s", pr_r.medir_name);
 		printf("%d-%d-%d", pr_r.sDay, pr_r.sMonth, pr_r.sYear);
 		printf("%d", pr_r.qty);
 		printf("%.2f", pr_r.unit);
 		printf("%.2f", pr_r.rate);
 		printf("%.2f", pr_r.profit);
 		printf("%c", 124);
		j += 2;

	}
	getche();
 }

void sale_rpt_daily()
{
	char ch;
	int j, d, m, y;
	float total = 0.00;
	system("cls");
	ptrs_r = fopen("saleRpt.dat", "r");
	if (ptrs_r == NULL)
	{
		printf("\n\t Can not open File! ");
		exit(0);
	}
	system("cls");
 	printf("\nEnter Date(dd-mm-yyyy):  ");
	scanf("%d-%d-%d", &d, &m, &y);
	system("cls");
 	printf("\nPress any key to go to REPORT MENU ...........");
  
 
	printf("\n\nSales Report");

 	printf("\n\nID. Medicine Name.  Customer Name.   Qty.  Rate.  Total.   Date");
 	printf("===================================================================");
	j = 14;
	while (fscanf(ptrs_r, "%s %s %s %d %f %f %d %d %d\n", s_r.medi_id, s_r.medir_name, s_r.cust_name, &s_r.qty, &s_r.rate, &s_r.total, &s_r.sDay, &s_r.sMonth, &s_r.sYear) != EOF)
	{
		if (d == s_r.sDay && m == s_r.sMonth && y == s_r.sYear)
		{
 			printf("%s", s_r.medi_id);
 			printf("%s", s_r.medir_name);
 			printf("%s", s_r.cust_name);
 			printf("%d", s_r.qty);
 			printf("%.2f", s_r.rate);
 			printf("%.2f", s_r.total);
 			printf("%d-%d-%d", s_r.sDay, s_r.sMonth, s_r.sYear);
			j = j + 2;
			total = total + s_r.total;
		}
	}
 	printf("\n\n-------------------------------------------------------------------");
 	printf("\n\nTotal:        %.2f", total);
	getche();
 }

void pur_rpt_daily()
{
	char ch;
	int j, d, m, y;
	float total = 0.00;

	ptrp_r = fopen("purreport.dat", "r");
	if (ptrp_r == NULL)
	{
		printf("\n Can not open File! ");
		exit(0);
	}
	system("cls");
 	printf("\nEnter Date(dd-mm-yyyy):  ");
	scanf("%d-%d-%d", &d, &m, &y);
	system("cls");
 	printf("\n\nPress Enter to go to REPORT MENU ...........");
	t();
  
 	printf("\n\nPurchase Report");

 	printf("\n\nID. Medicine Name.  Supplier Name.   Qty.  Rate.  Total.   Date");
 	printf("===================================================================");
	j = 14;
	while (fscanf(ptrp_r, "%s %s %s %d %f %f %d %d %d\n", p_r.medi_id, p_r.medir_name, p_r.supp_name, &p_r.qty, &p_r.rate, &p_r.total, &p_r.sDay, &p_r.sMonth, &p_r.sYear) != EOF)
	{
		if (d == p_r.sDay && m == p_r.sMonth && y == p_r.sYear)
		{
 			printf("%s", p_r.medi_id);
 			printf("%s", p_r.medir_name);
 			printf("%s", p_r.supp_name);
 			printf("%d", p_r.qty);
 			printf("%.2f", p_r.rate);
 			printf("%.2f", p_r.total);
 			printf("%d-%d-%d", p_r.sDay, p_r.sMonth, p_r.sYear);
			j += 2;
			total = total + p_r.total;
		}
	}
 	printf("\n\n-------------------------------------------------------------------");
 	printf("\n\nTotal:        %.2f", total);
	getche();
 }
