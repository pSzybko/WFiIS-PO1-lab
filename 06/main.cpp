#include"include/Primitive.h"
#include"include/Product.h"
#include"include/Sum.h"
#include"include/Ratio.h"
#include<iostream>

void SumFormula ();
void RatioFormula ();
void ProductFormula ();

int main ()
{
  std::cout<<"SUM:\n";
  SumFormula();
  std::cout<<"\nRATIO:\n";
  RatioFormula();
  std::cout<<"\nPRODUCT:\n";
  ProductFormula();
  
  return 0;
}

void SumFormula ()
{
  // formula: ((((a*b)+(c+d))+(c+d))+(a/b))

  Primitive primA (1);
  Primitive primB (2);
  Primitive primC (3);
  Primitive primD (4); 

  // (a*b)
  Product prodAB (primA, primB);
  prodAB.PrintWithValue();
  
  // (c+d)
  Sum sumCD (primC, primD);
  sumCD.PrintWithValue();

  // (a/b)
  Ratio ratioAB (primA, primB);
  ratioAB.PrintWithValue();

  // (a*b)+(c+d)
  Sum sum1 (prodAB, sumCD);
  sum1.PrintWithValue();

  // ((a*b)+(c+d))+(c+d)
  Sum sum2 (sum1, sumCD);
  sum2.PrintWithValue();
  
  // (((a*b)+(c+d))+(c+d))+(a/b)
  Sum sum3 (sum2, ratioAB);
  sum3.PrintWithValue();

  primA.Set(0.1);
  primB.Set(0.2);
  primC.Set(0.3);
  primD.Set(0.4);

  sum3.PrintWithValue();
}

void RatioFormula ()
{
  // formula: ((((a*b)/(c+d))/(a*b))/(a/b))

  Primitive primA (1);
  Primitive primB (2);
  Primitive primC (3);
  Primitive primD (4); 

  // (a*b)
  Product prodAB (primA, primB);
  prodAB.PrintWithValue();
  
  // (c+d)
  Sum sumCD (primC, primD);
  sumCD.PrintWithValue();

  // (a/b)
  Ratio ratioAB (primA, primB);
  ratioAB.PrintWithValue();

  // (a*b)+(c+d)
  Ratio ratio1 (prodAB, sumCD);
  ratio1.PrintWithValue();

  // ((a*b)+(c+d))+(c+d)
  Ratio ratio2 (ratio1, prodAB);
  ratio2.PrintWithValue();
  
  // (((a*b)+(c+d))+(c+d))+(a/b)
  Ratio ratio3 (ratio2, ratioAB);
  ratio3.PrintWithValue();

  primA.Set(0.1);
  primB.Set(0.2);
  primC.Set(0.3);
  primD.Set(0.4);

  ratio3.PrintWithValue();
}

void ProductFormula ()
{
  // formula: ((((a*b)*(c+d))*(a*b))*(a/b))

  Primitive primA (1);
  Primitive primB (2);
  Primitive primC (3);
  Primitive primD (4); 

  // (a*b)
  Product prodAB (primA, primB);
  prodAB.PrintWithValue();
  
  // (c+d)
  Sum sumCD (primC, primD);
  sumCD.PrintWithValue();

  // (a/b)
  Ratio ratioAB (primA, primB);
  ratioAB.PrintWithValue();

  // (a*b)+(c+d)
  Product product1 (prodAB, sumCD);
  product1.PrintWithValue();

  // ((a*b)+(c+d))+(c+d)
  Product product2 (product1, prodAB);
  product2.PrintWithValue();
  
  // (((a*b)+(c+d))+(c+d))+(a/b)
  Product product3 (product2, ratioAB);
  product3.PrintWithValue();

  primA.Set(0.1);
  primB.Set(0.2);
  primC.Set(0.3);
  primD.Set(0.4);

  product3.PrintWithValue();

}

/* // OUTPUT:
SUM:
(1*2) = 2
(3+4) = 7
(1/2) = 0.5
((1*2)+(3+4)) = 9
(((1*2)+(3+4))+(3+4)) = 16
((((1*2)+(3+4))+(3+4))+(1/2)) = 16.5
((((0.1*0.2)+(0.3+0.4))+(0.3+0.4))+(0.1/0.2)) = 1.92

RATIO:
(1*2) = 2
(3+4) = 7
(1/2) = 0.5
((1*2)/(3+4)) = 0.285714
(((1*2)/(3+4))/(1*2)) = 0.142857
((((1*2)/(3+4))/(1*2))/(1/2)) = 0.285714
((((0.1*0.2)/(0.3+0.4))/(0.1*0.2))/(0.1/0.2)) = 2.85714

PRODUCT:
(1*2) = 2
(3+4) = 7
(1/2) = 0.5
((1*2)*(3+4)) = 14
(((1*2)*(3+4))*(1*2)) = 28
((((1*2)*(3+4))*(1*2))*(1/2)) = 14
((((0.1*0.2)*(0.3+0.4))*(0.1*0.2))*(0.1/0.2)) = 0.00014
*/
