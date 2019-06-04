#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <math.h>

#include <iostream>
using namespace std;

class Triangle
{
    double B, A, AB;
  public:

    Triangle() /*  ����������� ��� ���������� */
    {
      AB = 15;
      A = 5.1;
      B = 7.1;
      #ifdef DEBUG
			cout << "Triangle() ���������" << endl;
      #endif
	}

    Triangle(double pB, double pA=0.1, double pAB=1)
    /* ����������� � ����������� */
    {
      #ifdef DEBUG
			cout << "Triangle(pB, pA, pAB) ���������" << endl;
      #endif
      if(!(pA>0 && pB>0 && pAB>0 && (pA+pB)<M_PI))
        throw runtime_error("Bad input");
	  B = pB;
      A = pA;
      AB = pAB;
	}

	Triangle(const Triangle& triangle) /* ����������� ����������� */
	{
      #ifdef DEBUG
		cout <<"Triangle(const Triangle& triangle) ���������" << endl;
      #endif
      this->B = triangle.B;
      this->A = triangle.A;
      this->AB = triangle.AB;
    }

	~Triangle() /* ���������� */
	{
      #ifdef DEBUG
		cout << "~Triangle() ���������" << endl;
      #endif
	}

	friend  istream &operator >> ( istream &stream, Triangle& triangle)
	{
      #ifdef DEBUG
		cout << " istream ���������" << endl;
      #endif
      cout << "������� � ���� ������ ����� ������������� ��������(������� ����). ���� � ����� ������ ������ �������� ������� PI" << endl;
      cout << "������� ��������������� ������� ��, ���� � � �" << endl;
      double vA, vB, vAB;
      stream >> vAB >> vA  >> vB;
      if(!(vA>0 && vB>0 && vAB>0 && (vA+vB)<M_PI))
        throw 'o';
      triangle.AB=vAB;
      triangle.A=vA;
      triangle.B=vB;
      return stream;
    }

    double getAngleA() const /* ��������� ���� � */
	{
      #ifdef DEBUG
		cout << "getAngleA() ���������" << endl;
      #endif
      return A;
    }

	double getAngleB() const /* ��������� ���� � */
	{
      #ifdef DEBUG
		cout << "getAngleB() ���������" << endl;
      #endif
      return B;
    }

    double getSideAB() const /* ��������� ������� �� */
    {
      #ifdef DEBUG
		cout << "getSideAB() ���������" << endl;
      #endif
      return AB;
    }

    void setAngleA(double angle) /* ��������� ���� A */
    {
      #ifdef DEBUG
		cout << "setAngleA(double angle) ���������" << endl;
      #endif
      if(!(angle>0 && (angle+B)<M_PI))
        throw 'o';
      A = angle;
    }

    void setAngleB(double angle) /* ��������� ���� � */
    {
      #ifdef DEBUG
		cout << "setAngleB(double angle) ���������" << endl;
      #endif
      if(!(angle>0 && (angle+A)<M_PI))
        throw 'o';
      B = angle;
    }

    void setSideAB(double side) /* ��������� ������� �� */
    {
 	  #ifdef DEBUG
		cout << "setSideAB(double side) ���������" << endl;
      #endif
      if(!(side>0))
        throw 'o';
      AB = side;
    }

    friend ostream &operator << ( ostream &stream, const Triangle &triangle)  /* ����� ������ �������� �� ����� */
    {
      #ifdef DEBUG
		cout << " ostream ���������" << endl;
      #endif
      stream << "\t������� �� = " << triangle.AB << "\n\t���� � = "
      << triangle.A << "\n\t���� � = " << triangle.B <<"\n";
      return stream;
    }

    double Perimetr() /* �������� ����������� ��� */
    {
      #ifdef DEBUG
		cout << "Perimetr() ���������" << endl;
      #endif
      return AB + AB / sin(M_PI-A-B) * (sin(A) + sin(B));
    }

    double Median() /* �������, ����������� � ������� �� */
    {
      #ifdef DEBUG
		cout << "Median() ���������" << endl;
      #endif
      return 0.5 * sqrt(2 * AB / sin(M_PI-A-B) * sin(B) * AB / sin(M_PI-A-B) * sin(B) + 2 * AB / sin(M_PI-A-B) * sin(A) * AB / sin(M_PI-A-B) * sin(A) - AB * AB);
    }

    double Radius() /* ������ ��������� ���������� */
    {
      #ifdef DEBUG
		cout << "Radius() ���������" << endl;
      #endif
      return 0.5 * AB / sin(M_PI-A-B);
    }

   bool operator == (const Triangle &tri) /* ��������� ������������� �� ��������� */
    {
      #ifdef DEBUG
		cout << "operator == (tri) ���������" << endl;
      #endif
      if ((A==tri.A && B==tri.B && AB==tri.AB)||(A==(M_PI-tri.A-tri.B)
      && B==tri.A && AB==tri.AB*sin(tri.B)/sin(M_PI-tri.A-tri.B))||
      (A==tri.B && B==(M_PI-tri.A-tri.B) &&
      AB==tri.AB*sin(tri.A)/sin(M_PI-tri.A-tri.B)))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
};

#endif /* TRIANGLE_H_ */
