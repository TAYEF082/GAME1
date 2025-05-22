#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;

    cout<<"GAME_"<<endl;
    cout<<"1.Rock paper caesar"<<endl;
    cout<<"2.head tail"<<endl;

    cin>>n;


    if(n==1){

        int my=0,comp=0;

        int round;
        cout<<"select round-";
        cin>>round;

        while(1){
        char ch;
        cout<<"press R for Rock,P for paper,C for caesar-";
        cin>>ch;
        srand(static_cast<unsigned int>(time(0)));
        int ran = rand() % 3 + 1;

        if(ch=='R'&&ran==2)comp++;
        else if(ch=='R'&&ran==3)my++;
        else if(ch=='P'&&ran==3)comp++;
        else if(ch=='P'&&ran==1)my++;
        else if(ch=='C'&&ran==1)comp++;
        else if(ch=='C'&&ran==2)my++;

        cout<<"point:you="<<my<<" bot="<<comp<<" "<<endl;

        if(my==round){
            cout<<"you win"<<endl;
            break;
        }
        else if(comp==round){
            cout<<"bot win"<<endl;
            break;
        }


        }


    }
    else if(n==2){

            int wei;
            cout<<"select weicket-";
            cin>>wei;
            int over;
            cout<<"select over-";
            cin>>over;
            int ball=over*6;

            int my_toss;
            cout<<"press 1 for head and 2 for tail-> ";
            cin>>my_toss;

            srand(static_cast<unsigned int>(time(0)));

            int bot_toss = rand() % 2 + 1;
            int my_sel;int bot_sel;
            if(my_toss==bot_toss){
                cout<<"you win the toss,select 1 for bat or 2 for ball first->";
                cin>>my_sel;
            }

            else{
                srand(static_cast<unsigned int>(time(0)));

                bot_sel = rand() % 2 + 1;
                if(bot_sel==1)cout<<"bot win the toss and select bat first"<<endl;
                else  cout<<"bot win the toss and select ball first"<<endl;
            }

           ///one
           if(  (my_toss==bot_toss && my_sel==1) || (bot_sel==2)  ){//my bat
            int my_run=0;
            int wei2=wei;int ball2=ball;

            while(wei2!=0&&ball2!=0){
                int hit;
                cout<<"enter your run(1,2,3,4,6)-";
                cin>>hit;

                srand(static_cast<unsigned int>(time(0)));

                int bot_run;
                do {
                  bot_run = rand() % 6 + 1;
                } while (bot_run == 5);

                if(hit==bot_run){
                        wei2--;ball2--;
                     cout<<"your run is->"<<my_run<<" remain weicket is "<<wei2<<" remain ball is "<<ball2<<" "<<endl;

                }
                else {my_run=my_run+hit;ball2--;

                cout<<"your run is->"<<my_run<<" remain weicket is "<<wei2<<" remain ball is "<<ball2<<" "<<endl;
                }
            }
            cout<<"bot target run is->"<<my_run+1<<endl;

              wei2=wei;
              int bot_hit=0;int f=0;ball2=ball;
              while(wei2!=0&&ball2!=0){
                int hit;
                cout<<"enter your ball(1,2,3,4,6)-";
                cin>>hit;

                srand(static_cast<unsigned int>(time(0)));

                int bot_run;
                do {
                  bot_run = rand() % 6 + 1;
                } while (bot_run == 5);

                if(hit==bot_run){
                        wei2--;ball2--;
                        cout<<"bot run is->"<< bot_hit<<" need run "<<(my_run+1)-bot_hit<<" remain weicket "<<wei2<<" remain ball is "<<ball2<<" "<<endl;

                }
                else {bot_hit=bot_hit+bot_run;ball2--;

                cout<<"bot run is->"<< bot_hit<<" need run "<<(my_run+1)-bot_hit<<" remain weicket "<<wei2<<" remain ball is "<<ball2<<" "<<endl;
                }

                if(bot_hit>=my_run+1){
                    cout<<"bot win by "<<wei2<<" weicket"<<endl;
                    f++;
                    break;
                }
            }
            if(f==0  &&  (my_run-bot_hit!=0) ){
                cout<<"you win by "<<my_run-bot_hit<<" run"<<endl;
            }
            else if(f==0  &&  (my_run-bot_hit)==0) cout<<"match tye"<<endl;



           }


           ///two
           else if(  (my_toss==bot_toss && my_sel==2)  ||  (bot_sel==1)    ){//my ball first


            int wei2=wei;
            int bot_run=0;
            int ball2=ball;

            while(wei2!=0&&ball2!=0){
                int hit;
                cout<<"enter your bal(1,2,3,4,6)-";
                cin>>hit;

                srand(static_cast<unsigned int>(time(0)));

                int bot_hit;
                do {
                  bot_hit = rand() % 6 + 1;
                } while (bot_hit == 5);

                if(hit==bot_hit){
                        wei2--;ball2--;
                        cout<<"bot run is->"<<bot_run<<" remain weicket is "<<wei2<<" remains ball is "<<ball2<<" "<<endl;

                }
                else{
                    bot_run=bot_run+bot_hit;
                    ball2--;
                    cout<<"bot run is->"<<bot_run<<" remain weicket is "<<wei2<<" remains ball is "<<ball2<<" "<<endl;
                }




            }
            cout<<"bot target is "<<bot_run+1<<endl;

            wei2=wei;ball2=ball;
            int my_run=0;int f=0;
            while(wei2!=0&&ball2!=0){
                int hit;
                cout<<"enter your run(1,2,3,4,6)-";
                cin>>hit;

                srand(static_cast<unsigned int>(time(0)));

                int bot_hit;
                do {
                  bot_hit = rand() % 6 + 1;
                } while (bot_hit == 5);

                if(bot_hit==hit){
                        wei2--;ball2--;
                        cout<<"my run is->"<< my_run<<" need run "<<(bot_run+1)-my_run<<" remain weicket "<<wei2<<" remains ball is "<<ball2 <<" "<<endl;

                }
                else{
                    my_run=my_run+hit;
                    ball2--;
                    cout<<"my run is->"<< my_run<<" need run "<<(bot_run+1)-my_run<<" remain weicket "<<wei2<<" remains ball is "<<ball2 <<" "<<endl;

                }

                if(my_run>=(bot_run+1)) {
                    cout<<"you win by "<<wei2<<" weicket"<<endl;
                    f++;
                    break;
                }





           }
           if(f==0 && (bot_run-my_run!=0)   )cout<<"bot win by "<<bot_run-my_run<<" run"<<endl;
           else if( f==0 && (bot_run-my_run==0)      ) cout<<"match tye"<<endl;



    }






    }//if(n==2) end





}//main finction
