#include <gtest/gtest.h>
#include <sstream>
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"
#include "figure_array.h"

// ======= Тестовые точки =======
std::vector<Figure::Point> t_pts_vec = {{0,0}, {4,0}, {0,3}};
std::vector<Figure::Point> h_pts_vec = {{0,0},{2,0},{3,1},{2,2},{0,2},{-1,1}};
std::vector<Figure::Point> o_pts_vec = {{0,0},{2,0},{3,1},{3,3},{2,4},{0,4},{-1,3},{-1,1}};

// ======= Triangle =======
TEST(TriangleTest, Area) {
    Triangle t(t_pts_vec);
    EXPECT_DOUBLE_EQ(t.area(), 6.0);
}

TEST(TriangleTest, Center) {
    Triangle t(t_pts_vec);
    auto c = t.center();
    EXPECT_DOUBLE_EQ(c.first, (0+4+0)/3.0);
    EXPECT_DOUBLE_EQ(c.second, (0+0+3)/3.0);
}

TEST(TriangleTest, Equality) {
    Triangle t1(t_pts_vec);
    Triangle t2(t_pts_vec);
    EXPECT_TRUE(t1 == t2);
}

// ======= Hexagon =======
TEST(HexagonTest, Area) {
    Hexagon h(h_pts_vec);
    EXPECT_GT(h.area(), 0.0);
}

TEST(HexagonTest, Center) {
    Hexagon h(h_pts_vec);
    auto c = h.center();
    EXPECT_GT(c.first, 0.0);
    EXPECT_GT(c.second, 0.0);
}

TEST(HexagonTest, Equality) {
    Hexagon h1(h_pts_vec);
    Hexagon h2(h_pts_vec);
    EXPECT_TRUE(h1 == h2);
}

// ======= Octagon =======
TEST(OctagonTest, Area) {
    Octagon o(o_pts_vec);
    EXPECT_GT(o.area(), 0.0);
}

TEST(OctagonTest, Center) {
    Octagon o(o_pts_vec);
    auto c = o.center();
    EXPECT_GT(c.first, 0.0);
    EXPECT_GT(c.second, 0.0);
}

TEST(OctagonTest, Equality) {
    Octagon o1(o_pts_vec);
    Octagon o2(o_pts_vec);
    EXPECT_TRUE(o1 == o2);
}

// ======= FigureArray =======
TEST(FigureArrayTest, AddRemove) {
    FigureArray arr;
    auto* t = new Triangle(t_pts_vec);
    arr.push_back(t);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_TRUE(*arr[0] == *t);

    arr.remove(0);
    EXPECT_EQ(arr.size(), 0);
}

TEST(FigureArrayTest, TotalArea) {
    FigureArray arr;
    arr.push_back(new Triangle(t_pts_vec));
    arr.push_back(new Triangle(t_pts_vec));
    EXPECT_DOUBLE_EQ(arr.totalArea(), 12.0);
}

TEST(FigureArrayTest, IndexAccess) {
    FigureArray arr;
    auto* h = new Hexagon(h_pts_vec);
    arr.push_back(h);
    EXPECT_TRUE(arr[0] == h);
}

// ======= IO Tests =======
TEST(FigureIOTest, TriangleReadWrite) {
    Triangle t(t_pts_vec);
    std::stringstream ss;
    ss << t;
    Triangle t2;
    ss >> t2;
    EXPECT_TRUE(t == t2);
}

TEST(FigureIOTest, HexagonReadWrite) {
    Hexagon h(h_pts_vec);
    std::stringstream ss;
    ss << h;
    Hexagon h2;
    ss >> h2;
    EXPECT_TRUE(h == h2);
}

TEST(FigureIOTest, OctagonReadWrite) {
    Octagon o(o_pts_vec);
    std::stringstream ss;
    ss << o;
    Octagon o2;
    ss >> o2;
    EXPECT_TRUE(o == o2);
}

// ======= Edge Cases =======
TEST(FigureArrayTest, RemoveInvalidIndex) {
    FigureArray arr;
    arr.remove(5); // не должно ломаться
    EXPECT_EQ(arr.size(), 0);
}

TEST(FigureArrayTest, EmptyArrayTotalArea) {
    FigureArray arr;
    EXPECT_DOUBLE_EQ(arr.totalArea(), 0.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
