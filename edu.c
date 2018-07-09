#include "stdio.h"
#include "string.h"
#include "process.h"
#include "stdlib.h"
#define p printf
#define s scanf
#define cl system("cls")
#include "stddef.h"
#include <math.h>
#include <time.h>

typedef char string[20];

int ch,t,tt=-20,i,j,co,ci,aa,bb;
enum aff {yes,no};
string s1,ss="";FILE *f,*fp;

struct weather
{
	int humidity;
	int temp;
	int wind;
	int pollution;
	int precipitation;
    string remark;	
};
struct town
{
	string city;
	struct weather wt;
}dk;
struct country
{ string cn;
  struct town ct[50];
}con[50],du;
//Structures
int in()
{
	string q;int n;

    while(1)
    {	s("%s",q);
	n=atoi(q);
	if(n==0)
	p("\aplease enter an Integer-->");
	else
	return n;
	}
    
}
ran()
{ 
int t,h,po,pr,w;
    if(tt!=-20)
    {    
    	t=rand()%8+(tt-4); 
	}
	else
	t = (rand()%40)-5;
	   if(t<10)
	   {
	   	h=rand()%40+40;
	   }
	   else if(t>30)
	   {
	   	h=rand()%20+20;
	   }
	   else
	   h=rand()%73+7;
       w=rand()%15+2;
       if(rand()%2+1==1)
       w+=rand()%3+1;
       else
       w-=rand()%3+1;
       po=2;
       if(rand()%2+1==1)
       {
       po-=1;
       }
	   else if(rand()%2+1==1)
       {
       	po=po;
	   }
       else
       {if(rand()%2+1==1)
       po-=1;
       else
	   po+=1;
}   
    if(t<30)
    pr=rand()%90+10;
    else
    pr=rand()%60+10;
   if(po>2)
strcpy(s1,"PREFER A FACE MASK, ITS POLLUTED EVERYWHERE");
else if(pr>70)
strcpy(s1,"TAKE YOUR UMBRELLA, IT MIGHT RAIN");
else if(t>28)
{
strcpy(s1,"IT'S HOT OUTSIDE");
}
else if(t<12)
{
strcpy(s1,"IT'S CHILLING OUTSIDE");
}
else if(w>12)
{
strcpy(s1,"IT'S A WINDY DAY");
}
else
strcpy(s1,"ALL CALM AND FINE");
    dk.wt.precipitation=pr;dk.wt.pollution=po;dk.wt.temp=t;dk.wt.wind=w;dk.wt.humidity=h;
}
sot(int l[])
{
	int i,j,o;struct town b;
	for(i=0;i<ci;i++)
	{
		for(j=0;j<ci-i-1;j++)
		{
			if(l[j]>l[j+1])
			{
				o=l[j];
				l[j]=l[j+1];
				l[j+1]=o;
				b=du.ct[j];
				du.ct[j]=du.ct[j+1];
				du.ct[j+1]=b;
			}
		}
	}
		
}
edit1()
{   cl;
	p("\t\t\t\tEDIT\n\t\t\t\t----\n\t\t\t\t>ALL\n\t\t\t\t>DATA\n\t\t\t\t>RANDOM\n\t\t\t\t>BACK\n\t\t\t\t>QUIT\n\t\t\tYour Input:");
	s("%s",s1); 
	if(stricmp(s1,"all")==0)
	{   f=fopen("weather.txt","w");fp=fopen("number.txt","w");
	    cl;
		p("\t\t\t\t=======\n\t\t\t\t |INPUT|\n\t\t\t\t=======\n\n\t\t\t\t");
        p("\n\n\t\t\tNO. OF COUNTRIES:");
        co=in();fprintf(fp,"%d",co);fputs("\n",fp);
        p("\n\n\t\t\tNO. OF CITIES:");
        ci=in();fprintf(fp,"%d",ci);fclose(fp);
		for(i=0;i<co;i++)
		{  cl; p("\nINPUT COUNTRY %d:",i+1);
		     scanf("%s",con[i].cn);
			for(j=0;j<ci;j++)
			{
				p("\nINPUT CITY %d:",j+1);
				s("%s",con[i].ct[j].city);
				p("\nTEMPERATURE:");
				con[i].ct[j].wt.temp=in();
				p("\nHUMIDITY:");
				con[i].ct[j].wt.humidity=in();
				p("\nWIND:");
				con[i].ct[j].wt.wind=in();
				p("\nPOLLUTION:");
				con[i].ct[j].wt.pollution=in();
				p("\nPRECIPITATION:");
				con[i].ct[j].wt.precipitation=in();
			}
			fwrite(&con[i],sizeof(con[i]),1,f);
		}fclose(f);
		
		
	}
	if(stricmp(s1,"data")==0)
	{
		goto dat;
		dat:
			{
			
			strcpy(ss,"comp");
	        show1();cl;
         	p("\t\t\t\tPRESENT DATA\n\t\t\t\t---------\n");
         	p("\nCOUNTRY\tCITY\tTEMPERATURE\tHUMID\tWIND\tPOLLUTE\tPRECIPITATION\n%s\n",con[aa].cn) ;
            p("PRESENT-%s\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n\n",con[aa].ct[bb].city,con[aa].ct[bb].wt.temp,con[aa].ct[bb].wt.humidity,con[aa].ct[bb].wt.wind,con[aa].ct[bb].wt.pollution,con[aa].ct[bb].wt.precipitation);
            	p("\n\n|\t\t\tENTER NEW DATA\t\t\t|");
				p("\nTEMPERATURE:");
				con[aa].ct[bb].wt.temp=in();
				p("\nHUMIDITY:");
				con[aa].ct[bb].wt.humidity=in();
				p("\nWIND:");
				con[aa].ct[bb].wt.wind=in();
				p("\nPOLLUTION:");
				con[aa].ct[bb].wt.pollution=in();
				p("\nPRECIPITATION:");
				con[aa].ct[bb].wt.precipitation=in();           
	    f=fopen("weather.txt","w");
        for(i=0;i<co;i++)
		{  
		fwrite(&con[i],sizeof(con[i]),1,f);
		}fclose(f);
	strcpy(ss,"");
	
	  p("\t\t\tDATA SUCCESFULLY EDITED\n-------------------------\n");
	p("NEW:    %s\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n\n",con[aa].ct[bb].city,con[aa].ct[bb].wt.temp,con[aa].ct[bb].wt.humidity,con[aa].ct[bb].wt.wind,con[aa].ct[bb].wt.pollution,con[aa].ct[bb].wt.precipitation);
p("\n\t\t\tDO YOU WANT TO EDIT MORE\n\t\t\t=========================\n\t\t\tYour Input:");
	   }
	   s("%s",s1);
	   if(stricmp(s1,"yes")==0)
	   goto dat;cl;
	  }
	  
	  if(stricmp(s1,"RANDOM")==0)
	  {cl;
	  f=fopen("weather.txt","w");fp=fopen("number.txt","w");
	  	p("\t\t\t\t=======\n\t\t\t\t|INPUT|\n\t\t\t\t=======\n\n\t\t\t\t");
        p("\n\n\t\t\tNO. OF COUNTRIES:");
        co=in();fprintf(fp,"%d",co);fputs("\n",fp);
        p("\n\n\t\t\tNO. OF CITIES:");
        ci=in();fprintf(fp,"%d",ci);fclose(fp);
		for(i=0;i<co;i++)
		{  cl; p("\nINPUT COUNTRY %d:",i+1);
		     scanf("%s",con[i].cn);
			for(j=0;j<ci;j++)
			{  
				p("\nINPUT CITY %d:",j+1);
				s("%s",con[i].ct[j].city);
	   {int t,h,po,pr,w;
	   srand(time(NULL));
	   t = (rand()%40)-5;
	   if(t<10)
	   {
	   	h=rand()%40+40;
	   }
	   else if(t>30)
	   {
	   	h=rand()%20+20;
	   }
	   else
	   h=rand()%73+7;
       w=rand()%15+2;
       if(rand()%2+1==1)
       w+=rand()%3+1;
       else
       w-=rand()%3+1;
       po=2;
       if(rand()%2+1==1)
       {
       po-=1;
       }
	   else if(rand()%2+1==1)
       {
       	po=po;
	   }
       else
       {if(rand()%2+1==1)
       po-=1;
       else
	   po+=1;
       }   
    if(t<30)
    pr=rand()%90+10;
    else
    pr=rand()%60+10;
			   
				
				con[i].ct[j].wt.temp=t;
			
				con[i].ct[j].wt.humidity=pr;
				
				con[i].ct[j].wt.wind=w;
				
				con[i].ct[j].wt.pollution=po;
			
				con[i].ct[j].wt.precipitation=h;}
			}fwrite(&con[i],sizeof(con[i]),1,f);
		}fclose(f);
	  }
		if(stricmp(s1,"quit")==0) exit(0);
	
}
compare1()
{
	strcpy(ss,"comp");
	show1();
	tt=con[aa].ct[bb].wt.temp;
	p("\nCOUNTRY\tCITY\tTEMPERATURE\tHUMID\tWIND\tPOLLUTE\tPRECIPITATION\n(%s)\n\t(%s)\n",con[aa].cn,con[aa].ct[bb].city) ;
    p("TODAY    -\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n\n",con[aa].ct[bb].wt.temp,con[aa].ct[bb].wt.humidity,con[aa].ct[bb].wt.wind,con[aa].ct[bb].wt.pollution,con[aa].ct[bb].wt.precipitation);
                  
	ran();
    
	p("YESTERDAY-\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n\n",dk.wt.temp,dk.wt.humidity,dk.wt.wind,dk.wt.pollution,dk.wt.precipitation);
   srand(time(NULL));
    ran();
    
    p("TOMORROW -\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n\n",dk.wt.temp,dk.wt.humidity,dk.wt.wind,dk.wt.pollution,dk.wt.precipitation);

	
strcpy(ss,"");tt=0;}
show1()
{cl;int tt;
	enum opt {current=1,all,search,sort,back,quit};
	do{
	 tt=0;
	 if(!(strcmp(ss,"comp")==0))
	{
	p("\t\t\t\tSHOW\n\t\t\t\t----\n\t\t\t\t>CURRENT\n\t\t\t\t>ALL\n\t\t\t\t>SEARCH\n\t\t\t\t>SORTED\n\t\t\t\t>BACK\n\t\t\t\t>QUIT\n\n\n\n\t\t\tYour Input:");
	s("%s",s1);} ch=0;
if(stricmp(s1,"current")==0)
ch=current;
else if(stricmp(s1,"all")==0)
ch=all;
else if(stricmp(s1,"search")==0)
ch=search;
else if(stricmp(s1,"sorted")==0)
ch=sort;
else if(stricmp(s1,"quit")==0)
ch=quit;
else if(stricmp(s1,"back")==0)
ch=back;
if(stricmp(ss,"comp")==0)
ch=search;


	switch(ch)
{   
    case back : break;
	case current :cl; srand(time(NULL));
	            p("\n\nDATE: %s\nTIME: %s\n",__DATE__,__TIME__);
	               p("\n\nCOUNTRY\tCITY\t  TEMPERATURE\tHUMID\tWIND\tPOLLUTE\tPRECIPITATION\nINDIA\n\tPHAGWARA");
	               ran();
	            p(" %7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n\n",dk.wt.temp,dk.wt.humidity,dk.wt.wind,dk.wt.pollution,dk.wt.precipitation);
p("\n\t\t\t\"%s\"",s1);
	               strcpy(ss,"");tt=0;
	               
	break;
	case all :cl;p("\t\t\t\tSHOW\n\t\t\t\t-----");
	        p("\n\nCOUNTRY\t%5.10s\t\tTEMPERATURE\tHUMID\tWIND\tPOLLUTE\tPRECIPITATION\n","CITY") ;
	         
			  for(i=0;i<co;i++)
		    {  
			    p("%s\t\t",con[i].cn);
			    
			      for(j=0;j<ci;j++)
			       {
			       	p("\n\t%10.10s|\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n",con[i].ct[j].city,con[i].ct[j].wt.temp,con[i].ct[j].wt.humidity,con[i].ct[j].wt.wind,con[i].ct[j].wt.pollution,con[i].ct[j].wt.precipitation);
	
			       }
			}
			       	fclose(f);
	break;
	case search : cl;
	p("\t\t\t\tSEARCH\n\t\t\t\t------");
	
                        goto conti;
						       conti:
                    		{
							
						           p("\n\t\t\tINPUT COUNTRY:");
                    	               s("%s",s1);
                    	               for(i=0;i<co;i++)
                    	          {
								  
                    	               if(stricmp(s1,con[i].cn)==0)
                    	               { goto citi;
                    	               	citi:
                    	               		{
											   
                    	               	p("\n\t\t\tENTER CITY :");
                    	               	s("%s",s1);
                    	               	for(j=0;j<ci;j++)
                    	               	{
                    	               		if(stricmp(s1,con[i].ct[j].city)==0)
                    	               		{ 
                    	               		if(stricmp(ss,"comp")==0)
                    	               		{
                    	               			aa=i;bb=j;return 0;
											   }
	                                        p("\n\nCOUNTRY\t%5.10s\t\tTEMPERATURE\tHUMID\tWIND\tPOLLUTE\tPRECIPITATION\n","CITY") ;
			       	                        p("\n\t%10.10s|\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n",con[i].ct[j].city,con[i].ct[j].wt.temp,con[i].ct[j].wt.humidity,con[i].ct[j].wt.wind,con[i].ct[j].wt.pollution,con[i].ct[j].wt.precipitation);
                                            break;
											   }
										   }
									        }
										   if(j==ci)
										   {cl;
										   p("\a\n\n\n\t\tENTERED CITY IS NOT PRESENT IN THE LIST");sleep(1);cl;
										   p("\t\t\t\tLIST\n\t\t\t\t----\n");
										   for(j=0;j<ci;j++)
										   {
										   	p("\t\t\t>%s\n",con[i].ct[j].city);
										   }
										   	goto citi;
										   }
										   else break;
										   
									   }
                    	          }
                    	      }
                    	      if(i==co)
										   {cl;
										   p("\a\n\n\n\t\tENTERED COUNTRY IS NOT PRESENT IN THE LIST");sleep(1);cl;
										   p("\t\t\t\tLIST\n\t\t\t\t----\n");
										   for(j=0;j<co;j++)
										   {
										   	p("\t\t\t>%s\n",con[j].cn);
										   }
										   	goto conti;
										   }
					
	break;
	case sort :cl; p("\t\t\t\tSORT\n\t\t\t\t----\n\n");   
	             goto contin;
						       contin:
                    		{
							
						           p("\n\t\t\tENTER COUNTRY :");
                    	               s("%s",s1);
                    	               for(i=0;i<co;i++)
                    	          {
                    	          	if(strcmp(s1,con[i].cn)==0)
                    	          	{ du=con[i];
                    	          	int ii,jj,x[50];
                    	          	do
                    	          	{
									  
                    	          	int t=0;
                    	          		p("\t\t\t\tSHOW\n\t\t\t\t----\n\t\t\t\t>TEMPERATURE\n\t\t\t\t>HUMIDITY\n\t\t\t\t>WIND\n\t\t\t\t>POLLUTION\n\t\t\t\t>PRECIPITATION\n\t\t\tYour Input:");
                    	          			s("%s",s1); 
if(stricmp(s1,"temperature")==0)
ch=0;
if(stricmp(s1,"humidity")==0)
ch=1;
if(stricmp(s1,"wind")==0)
ch=2;
if(stricmp(s1,"pollution")==0)
ch=3;
if(stricmp(s1,"precipitation")==0)
ch=4;                               

  switch(ch)
                                         {
                                         	case 0:
                                         	for(ii=0;ii<ci;ii++)
                                         	{
                                         		x[ii]=con[i].ct[ii].wt.temp;
											 }
											 sot(x);break;
                                         	case 1:for(ii=0;ii<ci;ii++)
                                         	{
                                         		x[ii]=con[i].ct[ii].wt.humidity;
											 }
											 sot(x);break;
                                         	case 2:for(ii=0;ii<ci;ii++)
                                         	{
                                         		x[ii]=con[i].ct[ii].wt.wind;
											 }
											 sot(x);break;
                                         	case 3:for(ii=0;ii<ci;ii++)
                                         	{
                                         		x[ii]=con[i].ct[ii].wt.pollution;
											 }
											 sot(x);break;
                                         	case 4:for(ii=0;ii<ci;ii++)
                                         	{
                                         		x[ii]=con[i].ct[ii].wt.precipitation;
											 }
											 sot(x);break;
                                          	default   : p("\n\n\n\t\t\t\tUnexpected Input,Please Try another Input.\n\t\t\t\t-------------------------------------.");t=-1;sleep(2);cl;
										 }
									}while(t==-1);
                                            
									 p("\n\nCOUNTRY\t%5.10s\t\tTEMPERATURE\tHUMID\tWIND\tPOLLUTE\tPRECIPITATION\n%s\n","CITY",con[i].cn) ;
                                    for(ii=0;ii<ci;ii++)
                                    {
                                    
			       	                        p("\n\t%10.10s|\t%7dC\t%3d%%\t%dkm/hr\t%3dPPM\t%7d%%\n",du.ct[ii].city,du.ct[ii].wt.temp,du.ct[ii].wt.humidity,du.ct[ii].wt.wind,du.ct[ii].wt.pollution,du.ct[ii].wt.precipitation);
                                            
									}
									  break;}
                    	          }
                    	      }
                    	      if(i==co)
										   {cl;
										   p("\a\n\n\n\t\tENTERED COUNTRY IS NOT PRESENT IN THE LIST");sleep(1);cl;
										   p("\t\t\t\tLIST\n\t\t\t\t----\n");
										   for(j=0;j<co;j++)
										   {
										   	p("\t\t\t>%s\n",con[j].cn);
										   }
										   	goto contin;
										   }
	
	break;
	case quit:exit(0);
	default   : p("\n\n\n\t\t\t\tUnexpected Input,Please Try another Input.\n\t\t\t\t-------------------------------------.");tt=-1;sleep(2);cl;

}
}while(tt==-1);
}
void main() 
{ 
f=fopen("weather.txt","r");fp=fopen("number.txt","r");
fscanf(fp,"%d",&co);fscanf(fp,"%d",&ci);fclose(fp);
        for(i=0;i<co;i++)
		{  
			 fread(&con[i],sizeof(con[i]),1,f);
		}
		
		
		//reading file
		 p("\n\n\n\n\n\n\n");
	p("    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	p("    %%                                                                    %%\n");
	p("    %%  WW     WW  EEEEEE  LL       CCCCCC  OOOOOOO  MMMMMMMMM  EEEEEEE   %%\n");
	p("    %%  WW     WW  EEE     LL       CC      OO   OO  MM MMM MM  EEE       %%\n");
	p("    %%  WW  W  WW  EEEEEE  LL       CC      OO   OO  MM  M  MM  EEEEEEE   %%\n");
	p("    %%  WW WWW WW  EEE     LL       CC      OO   OO  MM     MM  EEE       %%\n");
	p("    %%  WWWWWWWWW  EEEEEE  LLLLLLL  CCCCCC  OOOOOOO  MM     MM  EEEEEEE   %%\n");
	p("    %%                                                                    %%\n");
	p("    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	p("\n\t\t\t===================================\n\t\t\t** CSE PROJECT ON WEATHER REPORT **\n\t\t\t=================================== \n\n\n");
	p("\n\tSUBMITTED BY \t\t\t\t\tSUBMITTED TO");
	p("\n\t------------ \t\t\t\t\t------------");
	p("\n\tAbrar Ahmad Raza \t\t\t\tNahita Pathania");
	p("\n\tSection  : K17EZ");
	p("\n\tReg. No. : 11703115");
	p("\n\tRoll No. : A15");getch();
cl;
enum opt {edit=1,show,quit,compare};

goto cases;

cases:
	{
	
do{

p("\t\t\t\t*****************\n\t\t\t\tENTER YOUR CHOICE\n\t\t\t\t*****************\n\t\t\t\t>EDIT\n\t\t\t\t>SHOW\n\t\t\t\t>COMPARE\n\t\t\t\t>QUIT\n\n\n\n\n\t\t\tYour Choice :");
s("%s",s1); 
if(stricmp(s1,"edit")==0)
ch=edit;
if(stricmp(s1,"show")==0)
ch=show;
if(stricmp(s1,"quit")==0)
ch=quit;
if(stricmp(s1,"compare")==0)
ch=compare;
t=0;

switch(ch)
{
	case edit : edit1();break;
	case show : show1();break;
	case compare : compare1();break;
	case quit : exit(0);
	default   : p("\n\n\n\t\t\t\tUnexpected Input,Please Try another Input.\n\t\t\t\t----------------------------------------.");t=-1;sleep(2);cl;
}

}while(t==-1);


}
p("\n\n\n\n\t\t\tDO YOU WISH TO CONTINUE FROM MAIN MENU\n\t\t\t--------------------------------------\n\t\t\tYour Input:");
s("%s",s1); 
if(!stricmp(s1,"no")==0)

{cl;goto cases;}

else
{cl;
	p("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t*THANK YOU*");sleep(2);
exit(0);
}
}
