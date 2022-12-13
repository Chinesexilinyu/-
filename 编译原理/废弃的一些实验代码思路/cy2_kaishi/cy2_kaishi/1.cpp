#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;
//��������
string s, str, stackStr;//s�����봮��str���м������stackStr : ģ��ջ
int i;
string ch;//��ǰ�����ַ�
vector<string> v;//�ַ������͵�����(�ķ�+����ջ)
//��������
void E();                   //E-->TG
void G();                   //G-->+TG|��
void T();                   //T-->FS
void S();                   //S-->*FS|��
void F();                   //F-->(E)|i
void err();					//��ʾ������Ϣ
int check();//��֤�Ƿ��Ѿ���ջ��
void push(string pre, string value);//���ַ����������ջ
/**
 * �������ܣ���ʾ������Ϣ
 */
void err()
{
    cout << "ERROR" << endl;
    exit(0);
}
/**
 * �������ܣ����ַ����������ջ
 */
void push(string pre, string value)
{
    ch += s[i];
    int idx = stackStr.find_first_of(pre[0], 0);//��ͷ��ʼ�ҵ�pre��ʼ��λ��
    if (value != "��")//���ǿ���ʱ
    {
        string value1;
        value1 = value;
        if (value[0] == '+')value1 = "TG";
        if (value[0] == '*')value1 = "FS";
        if (value[0] == '(')value1 = "E";
        if (value[0] == 'i')value1 = "";
        stackStr.replace(idx, 1, value1);//����һ��pre��λ���滻Ϊvalue
    }
    else
    {
        stackStr.erase(idx, 1);//ɾ���Ӹ�λ�ÿ�ʼ��1���ַ�
    }
    v.push_back((pre + value + "," + stackStr));//����Ӧ�ı��ʽ��ջ�����ݴ����������vβ��
}
/**
 * �������ܣ���֤�Ƿ��Ѿ���ջ��
 */
int check()
{
    if (i >= s.size()) {
        return 1;
    }
    else if (s[i] == '#')
    {
        ch += '#';
        return 1;
    }
    return 0;
}
/**
 * �������ܣ�E-->TG
 */
void E()
{
    push("E-->", "TG");
    T();
    G();
}
/**
 * �������ܣ�G-->+TG|��
 */
void G() {
    if (s[i] == '+')
    {
        str = s[i];
        str += "TG";
        i++;
        push("G-->", str);
        T();
        G();
    }
    else
    {
        push("G-->", "��");
    }
}
/**
 * �������ܣ�T-->FS
 */
void T()
{
    push("T-->", "FS");
    F();
    S();
}
/**
 * �������ܣ�S-->*FS|��
 */
void S() {
    if (s[i] == '*')
    {
        str = s[i];
        str += "FS";
        i++;
        push("S-->", str);
        F();
        S();
    }
    else
    {
        push("S-->", "��");
    }
}
/**
 * �������ܣ�F-->(E)|i
 */
void F() {
    if (s[i] == '(')
    {
        i++;
        push("F-->", "(E)");
        E();
        if (s[i] == ')')
        {
            i++;
        }
        else
        {
            err();
        }
    }
    else if (s[i] == 'i')
    {
        i++;
        push("F-->", "i");
    }
    else
    {
        err();
    }
}
/**
 * �������ܣ�������
 */
int main() {
    cout << "===================================================" << endl;
    cout << "=== �ݹ��½����� ===" << endl;
    cout << "===================================================" << endl;
    cout << "===�������ַ��� (��#�Ž�����===" << endl;
    while (cin >> s) //����Ҫ�������ַ���
    {
        v.clear();
        i = 0;
        stackStr = "E#";//��ʼ��ջ
        E();
        if (check())
        {
            cout << "=====>\t\t ���봮������ȷ�� " << endl;
            cout << "�Ƶ��������£� " << endl;
            cout << "�ķ�\t\t����ջ\t\t��ǰ�����ַ�\n";
            cout << "E      \t\tE#\t\t" << s[0] << endl;//��ʼջ������
            int i;
            for (i = 0; i < v.size(); i++)
            {
                cout << v[i].substr(0, v[i].find_first_of(",", 0)) << "\t";
                cout << setiosflags(ios::right) << setw(10) << v[i].substr(v[i].find_first_of(",", 0) + 1) << "\t\t";
                cout << ch[i] << endl;
            }
        }
        else
            cout << "==>\t ���봮�����ϸ��ķ� " << endl;
    }

    return 0;
}

