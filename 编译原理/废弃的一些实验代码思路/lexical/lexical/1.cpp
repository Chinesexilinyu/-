# include<iostream>
# include<string>
# include<fstream>
# include<sstream>//������
# include<vector>
# include<map>
using namespace std;

bool isIdentifier(string s);//��ʶ��
bool isKeywords(string s);//�ؼ���
bool isDigit(string s);//��������
bool isOperator(string s);//�����
bool isOperator(char c);//�����
string result(string s);//���ݴ���Ĳ���s������Ӧ�����
int main()
{
    //=====================���Ժ����Ƿ���ȷ=============================
    /*if(isIdentifier("_s2ias"))
        cout << "�Ǳ�ʶ��" << endl;
    if (isKeywords("for"))
        cout << "�ǹؼ���" << endl;
    if (isDigit("12a42"))
        cout << "������" << endl;
    if (isOperator(">"))
        cout << "�������" << endl;
    result("?");*/
    //===================================================================

    string file = ("TestData1.txt");
    ifstream input(file);
    //�����ļ���,ע����룬�ı��ļ������ʽ�����Ŀһֱ����������

    ofstream output("Result.txt", ofstream::app);
    //�Ƚ�TtestData.txt���ݿ�����Result.txt��
    string copy;

    getline(input, copy, '\0');
    cout << copy << endl;//�����Ƿ���ȷ

    //��ʱinput�Ѿ�ָ�����ļ�β��Ϊ�˺���Ķ�ȡ����Ҫ�ر��ٴ�
    input.close();
    input.open(file);

    /*���Խ��Ҫ����ԭ�����������յ���ʽ�����������Result.txt�У�
    ͬʱҪ�ѽ���������Ļ��
    */
    output << "ԭ����:\n";
    output << copy;
    output << "�������:\n";

    string str;
    string words;

    cout << "�������:\n";
    while (getline(input, str)) //��ȡ�ļ�ÿһ�ζ�ȡһ��,����EOF����
    {
        //���������л�ȡ���ʣ���Ҫ�õ����������󣬼�istringstream
        istringstream strCin(str);
        string s;
        while (strCin >> words)
        {
            //ע�⴦���ţ�����int a,b;������һ������"a,b;��,����Ҫ����һ���ַ�������
            //�ĸ��������,������������鷳������û�У���ideд����д��һ������ֺ�ʱ��ide
            //���Զ�����ո������ͷ��㴦�����


            //1.���ȿ���ȷ�����ǹؼ��ֿ϶��ǵ�����Ϊһ�����ʵ�
            if (isKeywords(words))
            {
                s = result(words);
                cout << s << endl;
                output << s << endl;
                continue;
            }

            //2,�Ե��ʽ���ɨ�裬�϶��Ǳ�ʶ��������������ŷֺ�,���ֵȵȻ����һ��ĵ���
            vector<int> index = { 0 };
            vector<string> mulWords;//��words�ֽ�Ϊ�������
            for (int i = 0; i < words.length(); i++)
            {

                //���������λ�ģ�����"<=",">=","==","!="
                if ((i < words.length() - 1) && isOperator(words[i]) && isOperator(words[i + 1]))
                {
                    //����Ҫע��ֻ������������λ�����������+-,))�Ͳ���,����))����Ҫ���),)
                    if (string(words.begin() + i, words.begin() + i + 2) == "<=" ||
                        string(words.begin() + i, words.begin() + i + 2) == ">=" ||
                        string(words.begin() + i, words.begin() + i + 2) == "==" ||
                        string(words.begin() + i, words.begin() + i + 2) == "!=")
                    {
                        index.push_back(i);
                        index.push_back(i + 2);
                        ++i;
                    }
                    else if (isOperator(words[i]))
                    {
                        if (find(index.begin(), index.end(), i) == index.end())
                            index.push_back(i);
                        if (find(index.begin(), index.end(), i + 1) == index.end())
                            index.push_back(i + 1);

                    }
                }
                //���ţ��������Ϊ�ָ�
                else if (isOperator(words[i]))
                {
                    if (find(index.begin(), index.end(), i) == index.end())
                        //��������"a,b"�����±�0��1��a�ֿ���1��2�����ŷֿ���2��3��b�ֿ�
                        index.push_back(i);
                    if (find(index.begin(), index.end(), i + 1) == index.end())
                        index.push_back(i + 1);

                    //�����a<=b�������أ�һ������0��1��a�ֿ���1��2��<�ֿ���2��3��=�ֿ�
                    //3��4��b�ֿ���Ȼ�����ָ�����ʱ��ע��������ڶ��������������ԣ�����
                    //�����жϵ�1��2��2��3����������������2

                }

            }
            for (int i = 0; i < index.size() - 1; i++)
            {
                string rel;
                //��������"<="����Ҫ��ȡ��<=��
                /*if (isOperator(words[index[i]]) && isOperator(words[index[i + 1]]))
                {
                    rel = result(string(words.begin() + index[i], words.begin() + index[i + 2]));
                    ++i;
                }
                else*/
                rel = result(string(words.begin() + index[i], words.begin() + index[i + 1]));

                output << rel << endl;
                cout << rel << endl;
            }

        }
    }
    output << endl;
    output.close();
    input.close();
    system("pause");
    return 0;
}

bool isIdentifier(string s)//��ʶ��,����Ҫ��:ID=letter(letter|digit)*
{
    if (!isKeywords(s))//��ʶ�������ǹؼ���
    {
        if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))//����ĸ
        {
            for (int i = 1; i < s.length(); i++)
            {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
                    || (s[i] >= '0' && s[i] <= '9'))
                    continue;
                else return false;
            }
            return true;
        }
        return false;
    }
    return false;
}
bool isKeywords(string s)//�ؼ���
{
    static vector<string> keyVec = { "main", "int", "float", "double", "char",
        "if", "then","else", "switch", "case", "break", "continue", "while",
        "do", "for" };
    vector<string>::iterator result = find(keyVec.begin(), keyVec.end(), s);
    if (result != keyVec.end())
        return true;
    else return false;
}
bool isDigit(string s)//��������,NUM=digit digit*
{
    if (s[0] >= '0' && s[0] <= '9')
    {
        for (int i = 1; i < s.length(); ++i)
            if (s[i] >= '0' && s[i] <= '9')
                continue;
            else return false;
        return true;
    }
    return false;
}

bool isOperator(string s)//�����
{
    static vector<string> opeVec = { "=","+","-","*","/","<","<=","==","!=",
        ">",">=",";","(",")","?",":","," };
    vector<string>::iterator result = find(opeVec.begin(), opeVec.end(), s);
    if (result != opeVec.end())
        return true;
    else return false;
}

bool isOperator(char c)//�����
{
    static vector<char> opeVec = { '=','+','-','*','/','<',
        //"<=","==","!=",
        '>',
        //">=",
        ';','(',')','?',':',',' };
    vector<char>::iterator result = find(opeVec.begin(), opeVec.end(), c);
    if (result != opeVec.end())
        return true;
    else return false;
}

string result(string s)//���ݴ���Ĳ���s������Ӧ�����
{
    //�ֱ���
    //1.��ʶ��
    if (isIdentifier(s))
        return "(��ʶ��--10," + s + ")";

    //2.�ؼ���
    static map<string, string> keyMap;
    keyMap["int"] = "1";
    keyMap["float"] = "2";
    keyMap["if"] = "3";
    keyMap["switch"] = "4";
    keyMap["while"] = "5";//ֻд5���ɣ�û��Ҫȫд
    if (isKeywords(s))
        return "(�ؼ���--" + keyMap[s] + "," + s + ")";

    //3.���ͳ���
    if (isDigit(s))
        return "(���ͳ���--11," + s + ")";

    //4.�����
    static map<string, string> opeMap;
    opeMap["="] = "(�Ⱥ�--17��=��";
    opeMap["<"] = "(С�ں�--20,<)";
    opeMap["<="] = "(С�ڵ��ں�--21,<=)";
    opeMap["=="] = "(��ֵ�����--22��==��";
    opeMap["!="] = "(�����ں�--23,!=)";
    opeMap[">"] = "(���ں�--24,>)";
    opeMap[">="] = "(���ڵ��ں�--25,>=)";
    opeMap[";"] = "(�ֺ�--26,;)";
    opeMap["+"] = "(�Ӻ�--13,+)";
    opeMap["("] = "( ������--27,( )";
    opeMap["-"] = "(����--14,-)";
    opeMap[")"] = "(������--28,) )";
    opeMap[">"] = "(���ں�--24,>)";
    opeMap["*"] = "(�Ǻ�--15,*)";
    opeMap["?"] = "(�ʺ�--29,?)";
    opeMap["/"] = "(����--16,/)";
    opeMap[":"] = "(ð��--30,:)";
    opeMap[","] = "(����--31,,)";
    if (isOperator(s))
        return opeMap[s];
    return "Error";
}