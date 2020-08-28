//#include "Modular/Global.h"�˴��޸ĳ���һ����
#include "Global.h"



int main() {
    Start();
    int choice = 0;
    cin>>choice;
    while (choice){
        if(choice == 1) {
        cout <<"�ڶ��õ���������������\n";
        string filename = createSudokuToFile();
        cout <<filename<<"\n";
        cout <<"get answer\n";
        int VARNUM;
        HeadNode* LIST = CreateClause(VARNUM,filename);
        conse SudoResult[VARNUM];//��¼���յ����ֵ
        clock_t StartTime,EndTime;
        StartTime = clock();
        cout <<"get answer1\n";
        int value = SudoDPLL(LIST,SudoResult,VARNUM);
        cout <<"get answer2\n";
        EndTime = clock();
        cout<<"T "<<(double)(EndTime-StartTime)/CLOCKS_PER_SEC*1000.0<<" ms\n";
        if(value == 1)
            SudokuShow(SudoResult,VARNUM);
        else
            cout<<"there is no anwser.";
        }

        else if (choice == 2) {//SAT
            int VARNUM;
            string filename = "ais10.cnf";
            HeadNode* LIST = CreateClause(VARNUM,filename);
            consequence result[VARNUM];//��¼���յ����ֵ
            clock_t StartTime,EndTime;
            //cout<<"Result: \n";
            //StartTime = clock();
            //int value = DPLL(LIST,result);
            //EndTime = clock();
            //if(value) {
            //    cout << "S " << TRUE << endl;
            //    show(result, VARNUM);//�����
            //}
            //else {
            //    cout << "S " << NoAnwser << endl;
            //    cout<<"V "<<endl;
            //}
            //cout<<"T "<<(double)(EndTime-StartTime)/CLOCKS_PER_SEC*1000.0<<" ms\n";

             //д���ļ�
             string suffix = ".res";
             string name = "solution";
             string Outputfile = name + suffix;
             ofstream fos(Outputfile);
             if(!fos.is_open()) {
                 cout<<"Can not open a new file.\n";
                 exit;
             }

            StartTime = clock();
            int value = DPLL(LIST,result);
            EndTime = clock();
            //���
            if(value) {
                fos << "S " << TRUE << endl;
                fos<<"V ";
                for(int i = 0; i < VARNUM; i++) {
                    if (result[i].value == TRUE)
                        fos<<i+1<<" ";
                    else if(result[i].value == FALSE)
                        fos<<-(i+1)<<" ";
                    else
                        fos<<(i+1)<<" ";//ʣ��һ�ѿ�true��false�����������true
                }
                fos<<endl;
            }
            else {
                fos << "S " << NoAnwser << endl;
                fos<<"V ";
                fos<<endl;
            }
            //ʱ��
            fos<<"T "<<(double)(EndTime-StartTime)/CLOCKS_PER_SEC*1000.0<<" ms\n";
            fos.close();

        }
        else { //����ֵ�����
            cout<<"Please input the right number! ";
            exit;
        }
        choice = 0;
    }
}
