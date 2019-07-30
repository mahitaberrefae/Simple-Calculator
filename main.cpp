#include "inord_list.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

void countWord( ListElemtype e);
void starting (ListElemtype e);
void containing ( ListElemtype e);
void search ( ListElemtype e);

 inord_list MyList;
    ListElemtype Myelem;
    int FREQ;
    int li[1000];


int main(int argc, char *argv[])
{
    if(argc!=3)
       {
          cout<<"Incorrect Number of Arguments"<<endl;
          return 0;

       }
       else
       {



int SPACES=0;
string MyARR[10000];
string line;
ifstream infile;
ifstream commands;
string linec;
int wordnum=0;
int numdist=0;
int numchar=0;
int LINE =0;
int LINEC=0;

     for(int i=0; i<1000; i++)
    {
        li[i]=0;
    }

infile.open(argv[1]);

    if(infile.fail())
    {
        cout<<"File not found"<<endl;
        return 0;
    }


while(getline(infile, line))
    {
        LINE++;
    }

    infile.close();
infile.open(argv[1]);



for(int i=0; i<LINE; i++)
{ getline(infile, MyARR[i]);
}
infile.close();

infile.open(argv[1]);

for(int i=0; i<LINE; i++)
{
    int SIZE=MyARR[i].size();
    for (int j=0; j<SIZE; j++)
        {

        MyARR[i][j]=tolower(MyARR[i][j]);
    }
}




for(int i=0; i<LINE; i++)
{
  int SIZE=MyARR[i].size();
    replace(MyARR[i].begin(), MyARR[i].end(), ',', ' ');
    replace(MyARR[i].begin(), MyARR[i].end(), ';', ' ');
    replace(MyARR[i].begin(), MyARR[i].end(), ':', ' ');
    replace(MyARR[i].begin(), MyARR[i].end(), '&', ' ');
    replace(MyARR[i].begin(), MyARR[i].end(), '.', ' ');
    replace(MyARR[i].begin(), MyARR[i].end(), '"', ' ');
   replace(MyARR[i].begin(), MyARR[i].end(), '[', ' ');
   replace(MyARR[i].begin(), MyARR[i].end(), ']', ' ');
   replace(MyARR[i].begin(), MyARR[i].end(), '{', ' ');
   replace(MyARR[i].begin(), MyARR[i].end(), '}', ' ');
   replace(MyARR[i].begin(), MyARR[i].end(), '(', ' ');
   replace(MyARR[i].begin(), MyARR[i].end(), '’', ' ');
    replace(MyARR[i].begin(), MyARR[i].end(), ')', ' ');


  for(int j=0; j<SIZE; j++)
{
      if (MyARR[i][j]==39)
    {
        MyARR[i][j]==' ';
    }
  }
        for (int j=0; j<SIZE; j++)
        { int x=MyARR[i][j];
            if (x==32)
            SPACES++;
            }


  int spaceindx1=0;
    int spaceindx2=0;
    int spaceindx3=0;
        while(spaceindx3!=-1)
    {
        spaceindx2=MyARR[i].find(" ", spaceindx2);
Myelem=MyARR[i].substr(spaceindx1,spaceindx2-spaceindx1);
     if(Myelem!="")
     {
         MyList.Insert(Myelem, i+1);
         numchar=Myelem.size()+numchar;

     }




        spaceindx1=spaceindx2+1;
        spaceindx3=spaceindx2;
        spaceindx2++;

    }



}
numchar=numchar+SPACES+LINE;




commands.open(argv[2]);
if(commands.fail())
    {
        cout<<"File not found"<<endl;
        return 0;
    }

    while(getline(commands, linec))
    {
        LINEC++;
    }


    commands.close();
commands.open(argv[2]);

string MYCOM[10000];
for(int i=0; i<=LINEC; i++)
{ getline(commands, MYCOM[i]);

}
commands.close();
commands.open(argv[2]);


for(int i=0; i<LINEC; i++)
{
    if(MYCOM[i]=="\0")
    {

    }
    else
    {


              if(MYCOM[i]=="wordCount")
              {

               bool sttus;
                 sttus=MyList.First( Myelem, FREQ, li);
                   while (sttus!=false)
                   {

                        wordnum=FREQ+wordnum;


                         sttus=MyList.Next( Myelem,FREQ, li);
                   }
                   cout<<wordnum<<" "<<"words"<<endl;
              }
              else
              {
                 if(MYCOM[i]=="distWords" )
                 {
        bool sttus; int numdist=0;
                 sttus=MyList.First( Myelem, FREQ, li);
                   while (sttus!=false)
                   {

                          numdist++;




                         sttus=MyList.Next( Myelem,FREQ, li);

                    }
                  cout<<numdist<<" "<<"distinct words"<<endl;
                }
                 else
                 {
                     if(MYCOM[i]=="charCount" )
                     {
                         cout<<numchar<<" "<<"characters"<<endl;
                     }
                     else
                     {
                         if(MYCOM[i]=="frequentWord")
                         { cout<<"Most frequent word is:"<<" ";
                             bool status; int coun1; int coun2;
                        status=MyList.First(Myelem, FREQ, li);
                        while(Myelem== "a" || Myelem=="of" || Myelem== "the" || Myelem== "an" || Myelem=="in" || Myelem=="on" || Myelem== "and" || Myelem=="is" || Myelem== "are")
                        {
                            status=MyList.Next(Myelem, FREQ, li);
                        }
                        coun1=FREQ;
                   while (status!=false)
                   {
                   status=MyList.Next(Myelem, FREQ, li);
                   while(Myelem== "a" || Myelem=="of" || Myelem== "the" || Myelem== "an" || Myelem=="in" || Myelem=="on" || Myelem== "and" || Myelem=="is" || Myelem== "are")
                        {
                            status=MyList.Next(Myelem, FREQ, li);
                        }
                     coun2=FREQ;
              if(coun2>=coun1)
               {
                   coun1=coun2;
               }
                   }


            if(coun2>=coun1)
               {

    bool sttus; string e1;
         sttus=MyList.First( Myelem, FREQ, li);

                while (sttus!=false)
                    {

                     if(coun2==FREQ)
                       {
                        e1=Myelem;
                        if( e1!= "a" && e1!="of" && e1!= "the" && e1!= "an" && e1!="in" && e1!= "on" && e1!= "and" && e1!="is" && e1!= "are" )
                        {
                            cout<<e1<<" ";
                        }
                        sttus=MyList.Next( Myelem,FREQ, li);
                        while(sttus!=false)
                        {
                       if(coun2==FREQ)
                       {

                                   if(Myelem!= "a" && Myelem!="of" && Myelem!= "the" && Myelem!= "an" && Myelem!="in" && Myelem!= "on" && Myelem!= "and" && Myelem!="is" && Myelem!= "are" )
                                   {

                                   cout<<Myelem<<" ";
                                   }

                       }
                      sttus=MyList.Next( Myelem,FREQ, li);
                       }

                    }


              sttus=MyList.Next( Myelem,FREQ, li);
                        }



                    }


else
{
    if(coun1>coun2)
{

    bool sttus; string e3;
    sttus=MyList.First( Myelem, FREQ, li);

                  while (sttus!=false)
                    {
                     if(FREQ==coun1)
                       {
                           e3=Myelem;
                           if( e3!= "a" && e3!="of" && e3!= "the" && e3!= "an" && e3!="in" && e3!= "on" && e3!= "and" && e3!="is" && e3!= "are"  )
                           {
                               cout<<e3<<" ";
                           }

                        sttus=MyList.Next( Myelem,FREQ, li);

                        while(sttus!=false)
                        {
                            if(FREQ==coun1)
                             {

                                   if(Myelem!= "a" && Myelem!="of" && Myelem!= "the" && Myelem!= "an" && Myelem!="in" && Myelem!= "on" && Myelem!= "and" && Myelem!="is" && Myelem!= "are" )
                                      {


                                        cout<<Myelem<<" ";
                                      }
                                      }

                        sttus=MyList.Next( Myelem,FREQ, li);
                        }

                        }
                       sttus=MyList.Next( Myelem,FREQ, li);

                      }



                    }

}
cout<<endl;
                    }


                         else
                         { string Mycom;
                             Mycom=MYCOM[i].substr(0, 9);
                            if(Mycom=="countWord")
                            {
                                string Mystrng;
                                int m=MYCOM[i].find(" ", 9);
                                if(m==-1)
                                {
                                 cout<<"Incorrect number of arguments"<<endl;
                                }
                                else
                                {
                                  Mystrng=MYCOM[i].substr(10, -1);
                                  int k=Mystrng.find(" ", 0);
                                   if(k!=-1)
                                   {
                                       cout<<"Incorrect number of arguments"<<endl;
                                   }
                                   else

                                  {
                                      if(Mystrng=="\0")
                                      {
                                           cout<<"Incorrect number of arguments"<<endl;
                                      }
                                      else
                                      {
                                         countWord(Mystrng);
                                      }

                                  }

                                }


                            }






                           else
                            { Mycom=MYCOM[i].substr(0, 8);

                                if(Mycom=="starting")
                                {

                                     string Mystrng;
                                     int m=MYCOM[i].find(" ", 8);
                                          if(m==-1)
                                          {
                                              cout<<"Incorrect number of arguments"<<endl;
                                          }
                                          else
                                          {
                                           Mystrng=MYCOM[i].substr(9, -1);
                                            int k=Mystrng.find(" ", 0);
                                   if(k!=-1)
                                   {
                                       cout<<"Incorrect number of arguments"<<endl;
                                   }
                                   else
                                {
                                    if(Mystrng=="\0")
                                    {
                                         cout<<"Incorrect number of arguments"<<endl;
                                    }
                                    else
                                    {
                                        starting(Mystrng);
                                    }

                                }
                                }


                                }
                                else
                                {
                                   Mycom=MYCOM[i].substr(0, 10);
                                    if(Mycom=="containing")
                                    {
                                        string Mystrng;
                                        int m=MYCOM[i].find(" ", 10);
                                          if(m==-1)
                                          {
                                              cout<<"Incorrect number of arguments"<<endl;
                                          }
                                        else
                                          {
                                            Mystrng=MYCOM[i].substr(11, -1);
                                            int k=Mystrng.find(" ", 0);
                                            if(k!=-1)
                                            {
                                              cout<<"Incorrect number of arguments"<<endl;
                                            }
                                            else
                                             {
                                                 if(Mystrng=="\0")
                                                 {
                                                     cout<<"Incorrect number of arguments"<<endl;
                                                 }
                                                 else
                                                 {
                                                     containing(Mystrng);
                                                 }

                                              }
                                          }
                                   }
                                    else
                                    {
                                        Mycom=MYCOM[i].substr(0, 6);
                                        if(Mycom=="search")
                                        {
                                          string Mystrng;
                                          int m=MYCOM[i].find(" ", 6);
                                        if(m==-1)
                                          {
                                              cout<<"Incorrect number of arguments"<<endl;
                                         }
                                         else
                                         {
                                               Mystrng=MYCOM[i].substr(7, -1);
                                                int k=Mystrng.find(" ", 0);
                                                if(k!=-1)
                                                  {
                                                      cout<<"Incorrect number of arguments"<<endl;
                                                  }
                                                     else
                                                  {

                                                  if(Mystrng=="\0")
                                                  {
                                                      cout<<"Incorrect number of arguments"<<endl;
                                                  }
                                                  else
                                                  {
                                                      search(Mystrng);
                                                  }

                                            }


                                          }


                                        }
                                        else
                                        {
                                            cout<<"Undefined command"<<endl;
                                        }


                                    }

                                }

                            }
                         }
                     }

                 }
              }

    }





}

       }



return 0;



    }






    void countWord( ListElemtype e)
{
    bool sttus;
    sttus=MyList.First( Myelem, FREQ, li);
    while (sttus!=false)
    {
        if(e==Myelem)
        { cout<<Myelem<<" is repeated "<<FREQ<<" times"<<endl;



        }
        sttus=MyList.Next( Myelem,FREQ, li);
    }



}
void starting ( ListElemtype e)
{ bool sttus; string Myelemsz;
sttus=MyList.First( Myelem, FREQ, li);
while (sttus!=false)
{

    int sze= e.size();
    Myelemsz= Myelem.substr(0, sze);
    if(e==Myelemsz)
    {
       cout<<Myelem<<": "<<FREQ<<"\t";
    }
    sttus=MyList.Next( Myelem,FREQ, li);




}
cout<<endl;
}

void containing ( ListElemtype e)
{
    bool sttus; string Myelemsz;
sttus=MyList.First( Myelem, FREQ, li);
while (sttus!=false)
{
     int s=Myelem.size();
    int sze= e.size();
    for(int i=0; i<=s; i++)
    {
        Myelemsz= Myelem.substr(i, sze);
    if(e==Myelemsz)
    {
      cout<<Myelem<<": "<<FREQ<<"\t";
    }
    }

    sttus=MyList.Next( Myelem,FREQ, li );




}
cout<<" "<<endl;
}

void search ( ListElemtype e)
{
    bool sttus; string Myelemsz;
sttus=MyList.First( Myelem, FREQ, li);
while (sttus!=false)
{
     int s=Myelem.size();
    int sze= e.size();
    for(int i=0; i<=s; i++)
    {int d=0;
        Myelemsz= Myelem.substr(i, sze);
    if(e==Myelemsz)
    {
        cout<<Myelem<<":\tlines ";
        for(int j=0; j<FREQ; j++)
        {
            if(li[j]!=d &&li[j]!=0 )
            {

                 cout<<li[j]<<" ";
                 d=li[j];
            }


        }
         cout<<endl;




}
    }

    sttus=MyList.Next( Myelem,FREQ, li);




}
cout<<endl;
}










