#include "gtest/gtest.h"
#include <sstream>
#include <cmath>
#include "../include/Figures.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"

TEST(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(p.x, 0.0);
    EXPECT_DOUBLE_EQ(p.y, 0.0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(2.5, 3.7);
    EXPECT_DOUBLE_EQ(p.x, 2.5);
    EXPECT_DOUBLE_EQ(p.y, 3.7);
}

TEST(PentagonTest, DefaultConstructor) {
    Pentagon p;
    SUCCEED();
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon p;
    std::stringstream ss;
    ss << "0 0 1 0 1.309 0.9511 0.5 1.5388 -0.309 0.9511";
    ss >> p;
    
    double area = p.area();
    EXPECT_GT(area, 0.0);
    EXPECT_TRUE(std::abs(area - 1.720) < 0.1);
}

TEST(PentagonTest, CenterCalculation) {
    Pentagon p;
    std::stringstream ss;
    ss << "0 0 2 0 2 2 0 2 1 1";
    ss >> p;
    
    Point center = p.get_center();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(PentagonTest, InputOutputOperators) {
    Pentagon p1, p2;
    std::stringstream ss;
    
    ss << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss >> p1;
    
    std::stringstream output;
    output << p1;
    std::string result = output.str();
    EXPECT_FALSE(result.empty());
    EXPECT_NE(result.find("Pentagon"), std::string::npos);
}

TEST(PentagonTest, CopyConstructor) {
    Pentagon p1;
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss >> p1;
    
    Pentagon p2(p1);
    EXPECT_TRUE(p1 == p2);
}

TEST(PentagonTest, MoveConstructor) {
    Pentagon p1;
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss >> p1;
    
    Pentagon p2(std::move(p1));
    EXPECT_GT(p2.area(), 0.0);
}

TEST(PentagonTest, AssignmentOperator) {
    Pentagon p1, p2;
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss >> p1;
    
    p2 = p1;
    EXPECT_TRUE(p1 == p2);
}

TEST(HexagonTest, BasicFunctionality) {
    Hexagon h;
    std::stringstream ss;
    ss << "0 0 1 0 1.5 0.866 1 1.732 0 1.732 -0.5 0.866";
    ss >> h;
    
    Point center = h.get_center();
    double area = h.area();
    
    EXPECT_NEAR(center.x, 0.5, 0.001);
    EXPECT_NEAR(center.y, 0.866, 0.001);
    EXPECT_GT(area, 0.0);
}

TEST(HexagonTest, ComparisonOperator) {
    Hexagon h1, h2;
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1 0 0 1 1";
    ss >> h1;
    ss.clear();
    ss << "0 0 1 0 1 1 0 1 0 0 1 1";
    ss >> h2;
    
    EXPECT_TRUE(h1 == h2);
}

TEST(OctagonTest, BasicFunctionality) {
    Octagon o;
    std::stringstream ss;
    ss << "0.5 0.0 1.0 0.5 1.0 1.5 0.5 2.0 -0.5 2.0 -1.0 1.5 -1.0 0.5 -0.5 0.0";
    ss >> o;
    
    Point center = o.get_center();
    double area = o.area();

    EXPECT_NEAR(center.x, 0.0, 0.001);
    EXPECT_NEAR(center.y, 1.0, 0.001);
    EXPECT_GT(area, 0.0);
}

TEST(PolymorphismTest, FigurePointer) {
    std::unique_ptr<Figure> figure = std::make_unique<Pentagon>();
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss >> *figure;
    
    EXPECT_GT(figure->area(), 0.0);
    Point center = figure->get_center();
    EXPECT_TRUE(center.x >= 0 && center.y >= 0);
}

TEST(ConversionTest, DoubleConversion) {
    Pentagon p;
    std::stringstream ss;
    ss << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss >> p;
    
    double area1 = p.area();
    double area2 = static_cast<double>(p);
    
    EXPECT_DOUBLE_EQ(area1, area2);
}

TEST(EqualityTest, DifferentFigures) {
    Pentagon p1, p2;
    std::stringstream ss1, ss2;
    
    ss1 << "0 0 1 0 1 1 0 1 0.5 0.5";
    ss1 >> p1;
    
    ss2 << "0 0 2 0 2 2 0 2 1 1";
    ss2 >> p2;
    
    EXPECT_FALSE(p1 == p2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}