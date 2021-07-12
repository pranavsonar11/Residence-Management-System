#include<stdio.h>
#include<string.h>
#define size 30

//void diplay(struct accommodation *) ;

struct accommodation
{
  char firstname[50];
  char lastname[50];
  int accommodation_type;
  int idtype;
  struct idnum
  {
    char aadhaar[15];
    char passport[15];
    char empcode [15];
  }id;
  char address[100];
};

struct string
{
char ln[50];
};

struct type_of_accomodation{
 int block[10];
}type1,type2 ,type3;


int main()
{
    struct accommodation a[size];
    int n=0,choice=0,c ;
    int i=0,k=0,id;
    printf("enter total no. of accomodators : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        initialize(a,i); // insert
    }
    while(1)
    {
        printf("\nenter operation u want perform : \n1.Insert records\n2.Remove Duplicates\n3.Print records \n4.Sort record \n5.Search\n6.Delete\n7.Update\n8.Special reallocation ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                for(i=0;i<n;i++)
                {
                    insert(a,i); // insert
                }
                arrange(a,n);
                break;

            case 2 :
                duplicate(a,n);
                arrange(a,n);
                print(a,n);
                break;

            case 3 :
                printrecords(a,n);
                break;

            case 4 :
                quickSort(a,0,n-1);
                print(a,n);
                break;

            case 5 :
                search(a,n);
                break;

            case 6 :
                delete1(a,n);
                arrange(a,n);
                print(a,n);
                break;

            case 7 :
                update_Records(a,n);
                print(a,n);
                break;

            case 8 :
                arrange_accomodation(a,n);
                specialRequestAllocation(a,n);
                print(a,n);
                break;

            default :
                break;
        }
    printf("\nwant to proceed : 1.Yes & 0.No ");
    scanf("%d",&c);
    if(c==1)
        continue;
    else
        break;

    }


    return 0;
}

void insert(struct accommodation *a,int i)  // insert record
{

    printf("\n.......%d.........\n",i+1);
    if(i<size)
    {
        printf("\nenter ur firstname:");
        scanf("%s",&a[i].firstname);
        printf("\nenter ur lastname:");
        scanf("%s",&a[i].lastname);
         printf("\nenter ur accomodarion type:");
        scanf("%d",&a[i].accommodation_type);
        printf("\nenter idtype : ");
        scanf("%d",&a[i].idtype);
        if(a[i].idtype==0)
        {
            printf("\nenter ur adhaar details :");
            scanf("%s",&a[i].id.aadhaar);
        }
        else if(a[i].idtype==1)
        {
            printf("\nenter ur passport details :");
            scanf("%s",&a[i].id.passport);
        }
        else if(a[i].idtype==2)
        {
            printf("\nenter ur empcode details :");
            scanf("%s",&a[i].id.empcode);
        }
        else
        {
            printf("invalid entry");
            initialize(a,i);
        }
        //printf("\nenter ur address:");
        //scanf("%s",&a[i].address);

      }

    else
    {
        printf("\nnot enough accomodation");
        return ;
    }
}

void duplicate(struct accommodation a[], int n ) // duplicates will be found out on the basis of ID proof and here we r considering that every individual has only one ID proof
{
    int i=0,j=0;
    for(i=n-1;i>0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            printf("\n im searching duplicates ");
            if(a[i].idtype == a[j].idtype && a[i].idtype>0 )
            {
                if( ! ( strcmp(a[i].id.empcode,a[j].id.empcode) || strcmp(a[i].id.passport,a[j].id.passport) || strcmp(a[i].id.aadhaar,a[j].id.aadhaar) ) )
                {
                    printf("\n I found it");
                    initialize(a,j);
                }
            }
        }
    }
}

void initialize(struct accommodation a[], int j)  // initialize record

{
    a[j].firstname[0]='\0';
    a[j].lastname[0]='\0';
    a[j].accommodation_type=-1;
    a[j].idtype=-1;
    a[j].id.aadhaar[0]='\0';
    a[j].id.passport[0]='\0';
    a[j].id.empcode[0]='\0';
    a[j].address[0]='\0';
}

void showdata(struct accommodation a[], int j) // show record
{
    printf("\nfn=%s\nln=%s\nact=%d\nidt=%d\nadh=%s\npass=%s\nemc=%s\nadd=%s\n",a[j].firstname,a[j].lastname,a[j].accommodation_type,a[j].idtype
           ,a[j].id.aadhaar,a[j].id.passport,a[j].id.empcode,a[j].address);
}

void printrecords(struct accommodation a[],int n) // print records as passport -- aadhaar--empcode
{
    int i ;
    for(i=0;i<n;i++)
    {
        if(a[i].idtype==1)
            showdata(a,i);
    }
     for(i=0;i<n;i++)
    {
        if(a[i].idtype==0)
            showdata(a,i);
    }
    for(i=0;i<n;i++)
    {
        if(a[i].idtype==2)
            showdata(a,i);
    }
}


void search( struct accommodation a[] , int n ) // search employee info with first name and if more than one record occurs then print it alphabetically
{
    struct string x[n] ;
    struct string c;
    int k[n];
    printf("\nenter string u want to search: ");
    scanf("%s",&c.ln);
    printf("\n%s",c.ln);
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        int res =strcmp(a[i].firstname,c.ln);

        if(res==0)
        {
            k[j]=i;
            strcpy(x[j].ln , a[i].lastname);
            j++;
        }
    }
    if(j==0)
        printf("\nno search found ");
    arrange_alphabetically(x,j,k);
    for(i=0;i<j;i++)
    {
        showdata(a,k[i]);
    }
}

void arrange_alphabetically(struct string x[],int n , int k[])// arrange alphabetically
{
    struct string temp; // Pointer declaration
    int i,str;
    for(str = 0; str < n-1; ++str)
    {
        for(i = str+1; i < n; ++i)
        {
            if(strcmp( x[str].ln , x[i].ln) > 0) //comparing the strings
            {
               swap(&k[str],&k[i]);
               strcpy( temp.ln, x[str].ln ) ; // compared string being stored in temp
               strcpy( x[str].ln , x[i].ln ) ;
               strcpy( x[i].ln , temp.ln ) ;
            }
        }
    }
    return;
}

void print( struct accommodation a[] , int n) // print records
{
    int i=0;
    for(i=0;i<n;i++)
    {
        showdata(a,i);
    }
}

void quickSort( struct accommodation a[] , int l, int h) // sort record alphabetically
{
    printf("\nim in quicksort");
    if(l<h)
    {
        int loc=partition(a,l,h);
        quickSort( a, l , loc - 1 );
        quickSort( a, loc + 1 , h );
    }
    return ;
}

int partition (struct accommodation a[],int l,int h)
{
   int start=l,end=h;
   char pivot_firstname[20]={};
   char pivot_lastname[20]={};
   int i=0,j=0;
   while(a[l].firstname[i]!='\0')
   {
       pivot_firstname[i]= a[l].firstname[i] ;
        i++;
   }
   while(a[l].lastname[j]!='\0')
   {
       pivot_lastname[j]= a[l].lastname[j] ;
       j++;
   }

   while(start < end)
   {

        while( (strcmp(pivot_firstname ,a[start].firstname) >= 0 ) && start < h )
        {

            if(strcmp( pivot_firstname , a[start].firstname ) == 0)
            {
                if(strcmp(pivot_lastname , a[start].lastname) >= 0)
                    start++;
                else
                    break;
            }
            else
                start++;
        }
        while( (strcmp( pivot_firstname , a[end].firstname) <= 0 ) && end > l )
        {

             if(strcmp( pivot_firstname , a[end].firstname ) == 0)
            {
                if( strcmp( pivot_lastname , a[end].lastname) <= 0)
                    end--;
                else
                    break;
            }
            else
                end--;
        }
        if(start<end)
        {
            oswap(&a[start] , &a[end]);
        }

   }
   oswap(&a[l], &a[end]);
   return end;
}


void oswap(struct accommodation *a,struct accommodation *b) // swap two records
{
    struct accommodation temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


void arrange(struct accommodation a[],int n)  // arrange after deletion or update
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        if(a[i].idtype!=-1)
        {
            oswap(&a[i],&a[j]);
            j++;
        }
    }
}

void delete1(struct accommodation a[],int n)   // delete record
{
    int idtype ;
    char idnum[20];
    printf("\nenter ur idtype and id no. that u wanna delete : ");
    scanf("%d %s",&idtype,&idnum);
    int i;
    for(i=0;i<n;i++)
    {    printf("\nim searching");
        if(idtype==0)
        {
            if( strcmp(a[i].id.aadhaar,idnum) == 0)
            {
                printf("\n i deleted adhar");
                initialize(a,i);
                break;
            }
        }
        else if(idtype==1)
        {
            if( strcmp(a[i].id.passport , idnum) == 0 )
            {
                printf("\n i deleted passport");
                initialize(a,i);
                break;
            }
        }
        else if(idtype==2)
        {
            if( strcmp(a[i].id.empcode ,idnum )== 0 )
            {
                printf("\n i deleted empcode");
                initialize(a,i);
                break;
            }
        }
    }

}


void update_Records( struct accommodation a[] , int n) // update records
{
    int i=find_id(a,n);
    int field;
    printf("\nenter field u wanna update : \n1.firstname\n2.lastname\n3.acc type\n4.id\n5.address  ");
    scanf("%d",&field);
    if(field == 1)
    {
        a[i].firstname[0]='\0';
        printf("\nenter new firstname : ");
        scanf("%s",&a[i].firstname);
    }
    else if(field == 2)
    {
        a[i].lastname[0]='\0';
        printf("\nenter new lastname : ");
        scanf("%s",&a[i].lastname);
    }
    else if(field == 3)
    {
        printf("\nenter new acc type : ");
        scanf("%d",&a[i].accommodation_type);
    }
    else if(field==4)
    {
        a[i].id.aadhaar[0]='\0';
        a[i].id.passport[0]='\0';
        a[i].id.empcode[0]='\0';
        printf("\nenter new id type : \n0.aadhar\n1.passport\n2.empcode ");
        scanf("%d",&a[i].idtype);
        if(a[i].idtype==0)
        {
            printf("\nenter ur adhaar details :");
            scanf("%s",&a[i].id.aadhaar);
        }
        else if(a[i].idtype==1)
        {
            printf("\nenter ur passport details :");
            scanf("%s",&a[i].id.passport);
        }
        else if(a[i].idtype==2)
        {
            printf("\nenter ur empcode details :");
            scanf("%s",&a[i].id.empcode);
        }
        else
        {
            printf("invalid entry");
            initialize(a,i);
        }
    }
    else if(field==5)
    {
        a[i].address[0]='\0';
        printf("\nenter new address : ");
        scanf("%s",&a[i]. address);
    }



}
int b1=0,b2=0,b3=0;
void arrange_accomodation( struct accommodation a[] , int n)
{
    printf("\nim in arrange_accomodation_type ");
    int i=0 ;
    for(i=0;i<n;i++)
    {
        if(a[i].accommodation_type==1)
        {
            type1.block[b1]=1;
            b1++;
        }
        else if(a[i].accommodation_type==2)
        {
            type2.block[b2]=1;
            b2++;
        }
        else   if(a[i].accommodation_type==3)
        {
            type3.block[b3]=1;
            b3++;
        }

    }
}

void specialRequestAllocation(struct accommodation a[] , int n ) // special request to change allocation
{
    int t;
    int id=find_id(a,n);
    printf("\nenter type of allocation you want :\n1.type1\n2.type2\n3.type3 ");
    scanf("%d",&t);
    if(t==1)
    {
        if(b1<3)
        {
            printf("\ntyp1 block is available ");
            type1.block[b1]=1;
            a[id].accommodation_type=1;
            b1++;

        }
        else
            printf("\ntyp1 block is unavailable ");
    }
    else if(t==2)
    {
        if(b2<3)
        {
            printf("\ntyp2 block is available ");
            type2.block[b1]=1;
            a[id].accommodation_type=2;
            b2++;
        }
        else
            printf("\ntyp2 block is unavailable ");
    }
    else if(t==3)
    {
        if(b3<3)
        {
            printf("\ntyp3 block is available ");
            type3.block[b3]=1;
            a[id].accommodation_type=3;
            b3++;
        }
        else
            printf("\ntyp3 block is unavailable ");
    }
    else
        printf("\n No blocks available");

}

int find_id(struct accommodation a[],int n)  // find ID of employee to perform operations on data
{

    int idtype ;
    char idnum[20];
    printf("\nenter ur idtype and id no. that u wanna Update : ");
    scanf("%d %s",&idtype,&idnum);
    int i;
    for(i=0;i<n;i++)
    {    printf("\nim searching");
        if(a[i].idtype==0)
        {
            if( strcmp(a[i].id.aadhaar,idnum) == 0)
            {
                return i;
                break;
            }
        }
        else if(a[i].idtype==1)
        {
            if( strcmp(a[i].id.passport , idnum )== 0 )
            {
                return i;
                break;
            }
        }
        else if(a[i].idtype==2)
        {
            if( strcmp(a[i].id.empcode ,idnum )== 0 )
            {
                return i;
                break;
            }
        }
        else
        {
            printf("\nInvalid record ");
            return -1;
        }
    }

}

void swap(int *a , int *b )
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;

}







