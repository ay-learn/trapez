// METHODE DES TRAPEZES (Forme adaptative)
#include <math.h>
#include <stdio.h>

#define MAX 130

double fct(double x) { return (sqrt(x)); }

double qu_trapezes_adapt(double a, double b, double eps, int n);
double trapezoidal(double a, double b, double eps, int n);

int main() {
  int n = 10000;
  double a, b, eps, solution;
  a = 1;
  b = 1.3;
  eps = 1e-15;
  // solution = qu_trapezes_adapt(a, b, eps, n);
  solution = trapezoidal(a, b, eps, n);
  printf("Méthode des trapèzes (formule adaptative)\n");
  printf("I = %.20e", solution);

  return 0;
}

double qu_trapezes_adapt(double a, double b, double eps, int n) {
  long i, j, p;
  double h, s, err, t0, t;
  j = 1;
  p = 1;
  h = b - a;
  t0 = h * (fct(a) + fct(b)) / 2;
  err = 2 * eps;
  while ((fabs(err) > eps) && (j <= 130)) {
    h = h / 2.0;
    s = 0;
    for (i = 1; i <= (2 * p - 1); i++) {
      s += fct(a + (2 * i - 1) * h);
    }
    t = t0 / 2.0 + h * s;
    err = t - t0;
    t0 = t;
    p++;
    j++;
  }
  return t;
}

double trapezoidal(double a, double b, double eps, int n) {
  n = MAX - 1;
  double h = (b - a) / n;
  double integral = 0.0;
  // Vector x(n+1,0.0);
  double x[MAX];
  for (unsigned int p = 0; p <= n; p++)
    x[p] = a + p * h;
  for (unsigned int k = 1; k <= n; k++)
    integral += (fct(x[k - 1]) + fct(x[k])) * (h / 2);

  return integral;
}
