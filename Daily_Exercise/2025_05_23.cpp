#include <iostream>
#include <memory>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;//最好只进行一次计算，可能有bug

// 多项式项的结构定义
struct Term {
    int coef;  // 系数
    int exp;   // 指数
    shared_ptr<Term> next;
    
    Term(int c, int e) : coef(c), exp(e), next(nullptr) {}
};

// 多项式类定义
class Polynomial {
private:
    shared_ptr<Term> head;  // 头指针

public:
    Polynomial() : head(nullptr) {}
    
    // 添加一项到多项式
    void addTerm(int coef, int exp) {
        if (coef == 0) return;  // 系数为0则不添加
        
        auto newTerm = make_shared<Term>(coef, exp);
        
        // 如果链表为空或新项指数大于头节点指数
        if (!head || exp > head->exp) {
            newTerm->next = head;
            head = newTerm;
            return;
        }
        
        // 查找合适的插入位置
        auto current = head;
        while (current->next && current->next->exp > exp) {
            current = current->next;
        }
        
        // 如果指数相同则合并系数
        if (current->next && current->next->exp == exp) {
            current->next->coef += coef;
            // 如果合并后系数为0则删除该项
            if (current->next->coef == 0) {
                current->next = current->next->next;
            }
            return;
        }
        
        // 插入新项
        newTerm->next = current->next;
        current->next = newTerm;
    }
    
    // 多项式加法
    Polynomial add(const Polynomial& other) const {
        Polynomial result;
        auto p1 = head, p2 = other.head;
        
        while (p1 && p2) {
            if (p1->exp > p2->exp) {
                result.addTerm(p1->coef, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.addTerm(p2->coef, p2->exp);
                p2 = p2->next;
            } else {
                int sumCoef = p1->coef + p2->coef;
                if (sumCoef != 0) {
                    result.addTerm(sumCoef, p1->exp);
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        // 添加剩余项
        while (p1) {
            result.addTerm(p1->coef, p1->exp);
            p1 = p1->next;
        }
        while (p2) {
            result.addTerm(p2->coef, p2->exp);
            p2 = p2->next;
        }
        
        return result;
    }
    
    // 多项式减法
    Polynomial subtract(const Polynomial& other) const {
        Polynomial negated = other;
        // 取反所有系数
        for (auto p = negated.head; p; p = p->next) {
            p->coef = -p->coef;
        }
        return add(negated);
    }
    
    // 多项式乘法
    Polynomial multiply(const Polynomial& other) const {
        Polynomial result;
        
        for (auto p1 = head; p1; p1 = p1->next) {
            Polynomial temp;
            for (auto p2 = other.head; p2; p2 = p2->next) {
                temp.addTerm(p1->coef * p2->coef, p1->exp + p2->exp);
            }
            result = result.add(temp);
        }
        
        return result;
    }
    
    // 计算多项式在x处的值
    double evaluate(double x) const {
        double result = 0.0;
        for (auto p = head; p; p = p->next) {
            result += p->coef * pow(x, p->exp);
        }
        return result;
    }
    
    // 打印多项式
    void print() const {
        if (!head) {
            cout << "0" << endl;
            return;
        }
        
        auto p = head;
        cout << p->coef;
        if (p->exp > 0) cout << "x";
        if (p->exp > 1) cout << "^" << p->exp;
        
        p = p->next;
        while (p) {
            if (p->coef > 0) cout << " + ";
            else cout << " - ";
            
            cout << abs(p->coef);
            if (p->exp > 0) cout << "x";
            if (p->exp > 1) cout << "^" << p->exp;
            
            p = p->next;
        }
        cout << endl;
    }
    
    // 从用户输入构建多项式
    void inputFromUser(const string& prompt) {
        cout << prompt << endl;
        cout << "请输入多项式的项（每行输入一个项，格式为：系数 指数）" << endl;
        cout << "输入空行结束输入" << endl;
        
        string line;
        while (getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            int coef, exp;
            if (iss >> coef >> exp) {
                addTerm(coef, exp);
            } else {
                cout << "输入格式错误，请重新输入！" << endl;
            }
        }
    }
};

// 主函数
int main() {
    Polynomial p1, p2;
    
    // 从用户输入构建多项式
    p1.inputFromUser("=== 输入第一个多项式 ===");
    p2.inputFromUser("=== 输入第二个多项式 ===");
    
    cout << "\n你输入的多项式:" << endl;
    cout << "多项式 p1: ";
    p1.print();
    
    cout << "多项式 p2: ";
    p2.print();
    
    while (true) {
        cout << "\n请选择操作:" << endl;
        cout << "1. 加法 (p1 + p2)" << endl;
        cout << "2. 减法 (p1 - p2)" << endl;
        cout << "3. 乘法 (p1 * p2)" << endl;
        cout << "4. 计算多项式在指定点的值" << endl;
        cout << "5. 重新输入多项式" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入选项: ";
        
        int choice;
        cin >> choice;
        cin.ignore(); // 忽略输入缓冲区中的换行符
        
        switch (choice) {
            case 1: {
                Polynomial sum = p1.add(p2);
                cout << "p1 + p2 = ";
                sum.print();
                break;
            }
            case 2: {
                Polynomial diff = p1.subtract(p2);
                cout << "p1 - p2 = ";
                diff.print();
                break;
            }
            case 3: {
                Polynomial product = p1.multiply(p2);
                cout << "p1 * p2 = ";
                product.print();
                break;
            }
            case 4: {
                cout << "请输入x的值: ";
                double x;
                cin >> x;
                cin.ignore();
                cout << "p1(" << x << ") = " << p1.evaluate(x) << endl;
                cout << "p2(" << x << ") = " << p2.evaluate(x) << endl;
                break;
            }
            case 5:
                p1 = Polynomial();
                p2 = Polynomial();
                p1.inputFromUser("=== 输入第一个多项式 ===");
                p2.inputFromUser("=== 输入第二个多项式 ===");
                cout << "\n你输入的多项式:" << endl;
                cout << "多项式 p1: ";
                p1.print();
                cout << "多项式 p2: ";
                p2.print();
                break;
            case 0:
                cout << "退出程序..." << endl;
                return 0;
            default:
                cout << "无效的选项，请重新输入！" << endl;
        }
    }
    
    return 0;
}    