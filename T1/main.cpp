#include <string>
#include <iostream>
#include <iomanip>
#include "base-types.h"
#include "rectangle.h"
#include "parallelogram.h"
#include "compositeshape.h"
#include "concave.h"
void printLine(Shape *shape)
{
  std::cout << std::fixed;
  rectangle_t frameRect = shape->getFrameRect();
  double frRect1X = frameRect.pos.x - frameRect.width / 2;
  double frRect1Y = frameRect.pos.y - frameRect.height / 2;
  double frRect2X = frameRect.pos.x + frameRect.width / 2;
  double frRect2Y = frameRect.pos.y + frameRect.height / 2;
  std::cout << frRect1X << " " << frRect1Y << " ";
  std::cout << frRect2X << " " << frRect2Y;
}
int main()
{
  std::string figureName = "";
  size_t compShapeCapacity = 10;
  CompositeShape compositeShape(compShapeCapacity);
  bool badFigure = false;
  bool figureCommand = false;
  bool scaleCommand = false;
  double iScaleX = 0, iScaleY = 0, iScaleK = 1;
  while (std::cin)
  {
    std::cin >> figureName;
    if (badFigure)
    {
      badFigure = false;
      std::cerr << "Error occurred: points does not match the task condition.\n";
    }
    if (figureName == "PARALLELOGRAM")
    {
      figureCommand = true;
      point_t *pointsArray = nullptr;
      try
      {
        point_t A{}, B{}, C{};
        std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        Shape *shape = new Parallelogram(A, B, C);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument &e)
      {
        badFigure = true;
      }
      catch (...)
      {
        std::cerr << "Error occurred while building parallelogram.\n";
        return 2;
      }
      delete[] pointsArray;
    }
    if (figureName == "RECTANGLE")
    {
      figureCommand = true;
      point_t *pointsArray = nullptr;
      try
      {
        point_t A{}, C{};
        std::cin >> A.x >> A.y >> C.x >> C.y;
        Shape *shape = new Rectangle(A, C);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument &e)
      {
        badFigure = true;
      }
      catch (...)
      {
        std::cerr << "Error occurred while building rectangle.\n";
        return 2;
      }
      delete[] pointsArray;
    }
    if (figureName == "CONCAVE")
    {
      figureCommand = true;
      point_t *pointsArray = nullptr;
      try
      {
        point_t A{}, B{}, C{}, D{};
        std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
        Shape *shape = new Concave(A, B, C, D);
        compositeShape.push_back(shape);
      }
      catch (const std::invalid_argument &e)
      {
        badFigure = true;
      }
      catch (...)
      {
        std::cerr << "Error occurred while building concave.\n";
        return 2;
      }
      delete[] pointsArray;
    }
    if (figureName == "SCALE")
    {
      scaleCommand = true;
      std::cin >> iScaleX >> iScaleY >> iScaleK;
      if (iScaleK <= 0)
      {
        std::cerr << "Negative koeff.\n";
        return 2;
      }
    }
  }
  if (!(scaleCommand && figureCommand))
  {
    return 2;
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(1) << compositeShape.getArea() << " ";
  printLine(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printLine(compositeShape[i]);
  }
  compositeShape.isoScale({iScaleX, iScaleY}, iScaleK);
  std::cout << "\n";
  std::cout << compositeShape.getArea() << " ";
  printLine(compositeShape[0]);
  for (size_t i = 1; i < compositeShape.size(); ++i)
  {
    std::cout << " ";
    printLine(compositeShape[i]);
  }
  std::cout << "\n";
  return 0;
}
