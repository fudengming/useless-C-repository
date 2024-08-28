#include<iostream>
#include<regex>
using std::regex;
using std::cout;
using std::string;
using std::cin;
int main(){
    string your_gender;
    string your_lover_gender;
    string wife_or_husband;
    do{
        cout<<"你的性别是:";
        cin>>your_gender;
        if(your_gender!="男"&&your_gender!="女"){
            cout<<"你输了个什么...\n算了，看不懂，回去重输！\n输入\"男\"或\"女\"才可以哦...\n";
        }
    }while(your_gender!="男"&&your_gender!="女");
    do{
        cout<<"你恋人的性别是:";
        cin>>your_lover_gender;
        if(your_lover_gender!="男"&&your_lover_gender!="女"){
            cout<<"你输了个什么...\n算了，看不懂，回去重输！\n输入\"男\"或\"女\"才可以哦...\n";
        }
    }while(your_lover_gender!="男"&&your_lover_gender!="女");
    if(your_gender==your_lover_gender){
        switch(your_gender=="男" ? 1 : 2){
            case 1:
                cout<<"我靠哥们，你男同啊？\n咳咳，不过测试还得继续...\n敢问你对象是老公还是老婆？(怎么怪怪的...):";
                cin>>wife_or_husband;
                while(wife_or_husband!="老公"&&wife_or_husband!="老婆"){
                    cout<<"你输了个什么玩意？看不懂诶...\n给我滚回去重输！\n你对象是老公还是老婆？:";
                    cin>>wife_or_husband;
                }
            break;
            case 2:
                cout<<"我靠，你女同啊？\n咳咳，不过测试还得继续...\n敢问你对象是老公还是老婆？(怎么怪怪的...):";
                cin>>wife_or_husband;
                while(wife_or_husband!="老公"&&wife_or_husband!="老婆"){
                    cout<<"你输了个什么玩意？看不懂诶...\n给我滚回去重输！\n你对象是老公还是老婆？:";
                    cin>>wife_or_husband;
                }
            break;
        }
    }else{
        your_gender=="男" ? wife_or_husband="老婆" : wife_or_husband="老公";
    }
    short your_lover_age=0;
    string get_age;
    do{
        cout<<"你"<<wife_or_husband<<"的年龄:";
        cin>>get_age;
        if(!regex_match(get_age, regex("0(.\\d{1,10})?|-?[1-9]\\d{0,2}(.\\d{1,10})?"))){
            cout<<"你确定你输的是年龄？\n回去重输！\n";
        }
    }while(!regex_match(get_age, regex("0(.\\d{1,10})?|-?[1-9]\\d{0,2}(.\\d{1,10})?")));
    your_lover_age=std::stof(get_age);
    cout<<"\n";
    switch(your_lover_age>=100 ? 1 : (your_lover_age>=18 ? 2 : (your_lover_age>0 ? 3 : 4))){
        case 1:
            cout<<get_age<<"岁...？你"<<wife_or_husband<<"命真长...\n";
        break;
        case 2:
            cout<<"行吧，没啥问题...\n";
        break;
        case 4:
            cout<<"你"<<wife_or_husband<<"还没出生？\n";
        break;
        case 3:
            if(wife_or_husband=="老婆"){
                cout<<"变态！坐牢去吧！\n";
            }else{
                cout<<"我靠？还没成年呢就玩这么花？\n";
            }
        break;
    }
    return 0;
}
