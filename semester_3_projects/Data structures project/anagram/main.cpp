#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <string>
#include<time.h>
#include<windows.h>

using namespace std;
using namespace std::chrono;
class vertex
{
    public:
        vertex *left_child;
        string word;
        vertex *right_child;

        vertex(string word)
        {
            left_child=NULL;
            this->word=word;
            right_child=NULL;
        }
};
class tree
{
    public:
        vertex *ROOT;
        int noofwords;

        tree()
        {
            ROOT=NULL;
            noofwords=0;
        }

        void add_word(string word)
        {
            if(ROOT==NULL)
            {
               ROOT=new vertex(word);
            }
            else
            {
                vertex *temp=ROOT,*parent;
                while(temp!=NULL)
                {
                    parent=temp;

                    if(temp->word<word)
                        temp=temp->right_child;
                    else
                        temp=temp->left_child;
                }

                if(parent->word<word)
                    parent->right_child=new vertex(word);
                else
                    parent->left_child=new vertex(word);

            }
            noofwords++;
        }
        void search_word(string word,ofstream &log)
        {
            if(noofwords==0)
            {
                cout<<"\nno words stored";
                return;
            }
            else
            {
                vertex *temp=ROOT;
                while(temp!=NULL)
                {
                    if(temp->word==word)
                    {
                        cout<<"\nGiven word '"<<word<<"' exists in the dictionary ";
                        log<<"\nGiven word '"<<word<<"' exists in the dictionary ";
                        return;
                    }
                    else if(temp->word<word)
                        temp=temp->right_child;
                    else
                        temp=temp->left_child;
                }
               // cout<<"\nGiven word '"<<word<<"' does not exists in the dictionary ";
                return;
            }
        }
        bool is_empty()
        {
            if(noofwords==0)
                return true;
            else
                return false;

        }

        void print_words_inorder(vertex *NODE)
        {
            if(NODE!=NULL)
            {
                print_words_inorder(NODE->left_child);
                cout<<NODE->word<<"->";
                print_words_inorder(NODE->right_child);
            }
        }

        void print_words_postorder(vertex *NODE)
        {
            if(NODE!=NULL)
            {
                print_words_postorder(NODE->left_child);
                print_words_postorder(NODE->right_child);
                cout<<NODE->word<<"->";
            }
        }

        void print_words_preorder(vertex *NODE)
        {
            if(NODE!=NULL)
            {
                cout<<NODE->word<<"->";
                print_words_preorder(NODE->left_child);
                print_words_preorder(NODE->right_child);
            }
        }
};
class node
{
    public:

        node *next_alphabet;
        tree list;
        char letterS;
        char letterC;

        node()
        {
            next_alphabet=NULL;
        }

};
class A_Z
{
    private:
       node *head,*tail;

    public:
        A_Z()
        {
            node *temp1=new node;
            temp1->letterS='a';
            temp1->letterC='A';
            head=temp1;
            for(char S='b',C='B';S<='z';S++,C++)
            {
                node *temp=new node;
                temp->letterS=S;
                temp->letterC=C;
                temp1->next_alphabet=temp;
                temp1=temp;
                temp=NULL;
            }
            tail=temp1;
        }
        void add_word(string word)
        {
            node *temp=head;
            for(temp=head;temp!=NULL;temp=temp->next_alphabet)
            {
                if(temp->letterS==word[0] || temp->letterC==word[0])
                {
                    temp->list.add_word(word);
                    break;
                }
            }
        }
        void print_dictionary_inorder(void)
        {
            node *temp;
            for(temp=head;temp!=NULL;temp=temp->next_alphabet)
            {
                cout<<temp->letterC<<"= ";
                temp->list.print_words_inorder(temp->list.ROOT);
                cout<<endl<<endl<<endl<<endl<<endl;
            }
        }

        void print_dictionary_postorder(void)
        {
            node *temp;
            for(temp=head;temp!=NULL;temp=temp->next_alphabet)
            {
                cout<<temp->letterC<<"= ";
                temp->list.print_words_postorder(temp->list.ROOT);
                cout<<endl<<endl<<endl<<endl<<endl;
            }
        }

        void print_dictionary_preorder(void)
        {
            node *temp;
            for(temp=head;temp!=NULL;temp=temp->next_alphabet)
            {
                cout<<temp->letterC<<"= ";
                temp->list.print_words_preorder(temp->list.ROOT);
                cout<<endl<<endl<<endl<<endl<<endl;
            }
        }

        void print_dictionary_report()
        {
            cout<<"\n\t\t\t\t\t/////////////DICTIONARY SPECS////////////"<<endl;
            node *temp;
            int sum=0;
            for(temp=head;temp!=NULL;temp=temp->next_alphabet)
            {
                cout<<"\t\t\t\t\twords in "<<temp->letterC<<" are  =  "<<temp->list.noofwords<<endl;
                sum+=temp->list.noofwords;
            }
            cout<<"\t\t\t\t\t----------------------------------------"<<endl;
            cout<<"\t\t\t\t\tTOTAL WORDS in dictionary ARE "<<sum;
        }
        void search_from_dictionary(string word,ofstream &log)
        {
            node *temp;
            for(temp=head;temp!=NULL;temp=temp->next_alphabet)
            {
                if(temp->letterS==word[0] || temp->letterC==word[0])
                {
                    temp->list.search_word(word,log);
                        return;
                }
            }
        }
};
////////////////////////////////////////////////////////////
bool swapcheck(string str, int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}
void findPerms(string str, int index, int n,A_Z &obj,ofstream &log)
{
    if (index >= n)
	{
        obj.search_from_dictionary(str,log);
        return;
    }

    for (int i = index; i < n; i++) {
        bool check = swapcheck(str, index, i);
        if (check) {
            swap(str[index], str[i]);
            findPerms(str, index + 1, n,obj,log);
            swap(str[index], str[i]);
        }
    }
}
///////////////////////////////////////////////////////
int main()
{
  ifstream input;
  srand(time(0));
  time_t crrtm;ofstream log;
    log.open("log.txt",ios::app);
    crrtm=time(NULL);
    char *time=ctime(&crrtm);
    log<<"\n\n************************************************************";
    log<<"\n\t\t\tSESSION START";
    log<<"\n\t\t "<<time<<"\nLOG:";

  string take;
  A_Z dictionary;
  auto start = high_resolution_clock::now();
  input.open("dictionary.txt",ios::in);
  if(!input.is_open())
  {
    cout<<"\ncannot open dictionary.txt (file must be missing) cannot proceed";
      return(0);
  }
  cout<<"\n\t\t\tplease wait creating data base for quick searching.........";
  while(!input.eof())
  {
      input>>take;
      dictionary.add_word(take);
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(stop - start);
  cout<<"\n\t\t\t\tdata base created in "<<duration.count()<<" seconds"<<endl;
  cout<<"\npress any key to proceed";
  getchar();
  system("cls");

  dictionary.print_dictionary_report();
  cout<<"\npress any key to proceed";
  getchar();
  system("cls");
  char choice;
  do
  {
      cout<<"\n======================================================================================================================";
      cout<<"\n\t\t\t\t\t\t\twelcome";
      cout<<"\n======================================================================================================================";
      cout<<"\n\t\t\t\tPlease enter any word to find its anagrams : ";
      cin>>take;
      log<<"\nword entered: "<<take;
      auto start1 = high_resolution_clock::now();
      while(take.length()!=1)
      {

          auto start = high_resolution_clock::now();
          cout<<"\n\n"<<take.length()<<" letter words: "<<endl<<"================================================";
          log<<"\n\n"<<take.length()<<" letter words: "<<endl<<"================================================";

          findPerms(take,0,take.length(),dictionary,log);
          auto stop = high_resolution_clock::now();
          auto durationMS = duration_cast<milliseconds>(stop - start);
          auto durationS = duration_cast<seconds>(stop - start);
          auto durationM = duration_cast<minutes>(stop - start);
          cout<<"\n________________________________________________"<<endl<<take.length()<<" letter words took "<<durationM.count()<<":"<<durationS.count()<<":"<<durationMS.count()<<endl;
          log<<"\n________________________________________________"<<endl<<take.length()<<" letter words took "<<durationM.count()<<":"<<durationS.count()<<":"<<durationMS.count()<<endl;
          take.erase(take.begin()+rand()%take.length());
      }
      auto stop1 = high_resolution_clock::now();
      auto duration1MS = duration_cast<milliseconds>(stop1 - start1);
      auto duration1S = duration_cast<seconds>(stop1 - start1);
      auto duration1M = duration_cast<minutes>(stop1 - start1);
      cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\ntotal time taken "<<duration1M.count()<<":"<<duration1S.count()<<":"<<duration1MS.count()<<endl;
      log<<"\n=================================================\ntotal time taken "<<duration1M.count()<<":"<<duration1S.count()<<":"<<duration1MS.count()<<endl;

      cout<<"\n\ndo you want to search again (y/n) ";
      cin>>choice;
      system("cls");

  }while(choice=='y');

  log<<"\n\t\t\tSESSION END\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
  log.close();
}
