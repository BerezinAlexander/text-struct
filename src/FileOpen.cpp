#include "FileOpen.h"

FileOpen::FileOpen() //! ����������� (��������� ����)
{

}

FileOpen::~FileOpen() //! ���������� (��������� ����)
{
    F.close();
}

void FileOpen::FileOpenDir(string str) //!(��������) ��������� ���� ����� ����,�������� ������������
{

    const char *a = str.c_str();

    F.open(a,ios::in);
    if(!F.is_open()) //! �������� �� ������������� �����
    {
        cout << " Can't open file (Please select correct file!)" << "\n";
    }else
    {
        if (str.empty() == true )
        {
            cout << " Error" << "\n";
        }
        else
        {
            cout << " All ok!" << "\n";
        }
    }
}
void FileOpen::FileOpenCurentDir(string str) //!(��������) ��������� ���� � ����������� ����������
{

    #ifdef __linux__ /* ��� LINUX (��������� ������� ����������)*/
    char buffer[1024];
    if (getcwd(buffer, sizeof(buffer)) != NULL)
       {
            string PATH(buffer);
       }
    #elif _WIN32  /* ��� Windows (��������� ������� ����������)*/
    char buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer),buffer);
    string PATH(buffer);
    #endif

    //! �������� �� ������������� �������
    //{

    if ( CheckFormat(str,".txt") == false  ) { cout << " Not txt format (Please write with text format)\n"; return; }

    //}

    str = PATH + "\\" + str; //! ���������� ���� � ������
    const char *a = str.c_str(); //! ��������������� � const char *
    F.open(a,ios::in); //! ��������� ����
    if(!F.is_open()) //! �������� �� ������������� �����
    {
        cout << " Can't open file (Please select correct file!)" << "\n";
    }
    else
    {
        if (str.empty() == true )
        {
            cout << " Error. Empty file" << "\n";
        }
        else if( str.empty() == false )
        {
            cout << str << "\n";
            cout << " All ok!" << "\n";
        }
    }
}
bool CheckFormat(string str,const char* text) //! �������� �� ������������� �������
{
    size_t pos = 0;
     if( (pos = str.find(text)) == std::string::npos)
    {
        return false;
    }
    return true;
}
void FileOpen::ChoiseHowOpenPlan()
{
    int choise;
    cout << " Choise how you can open file: \n\n";
    cout << " 1. Open file in a curent directory.\n";
    cout << " 2. Open directory.\n\n";

    cin >> choise;
    cout << "\n";

    switch(choise)
    {
        case 1:
        cout << " Enter File Name" << "\n";
        cin >> str;
        FileOpenCurentDir(str);
        break;
        case 2:
        cout << " Enter File Directory" << "\n";
        cin >> str;
        cout << "\n";
        FileOpenDir(str);
        break;
        default: cout <<"Please choise number \n";

    }


}
