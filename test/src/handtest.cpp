#include <gtest/gtest.h>
#include <Hand.h>

TEST(HandTest, brodwayCreation)
{
    Hand reka(Card::Ac, Card::Ts);
    EXPECT_EQ("AcTs", reka.show());
    Hand reka1(Card::Ad, Card::Kd);
    EXPECT_EQ("AdKd", reka1.show());
    Hand reka2(Card::Qc, Card::As);
    EXPECT_EQ("AsQc", reka2.show());
    Hand reka3(Card::Ah, Card::Ks);
    EXPECT_EQ("AhKs", reka3.show());
    Hand reka4(Card::Kc, Card::Kh);
    EXPECT_EQ("KhKc", reka4.show());
    Hand reka5(Card::Jc, Card::Qs);
    EXPECT_EQ("QsJc", reka5.show());
    Hand reka6(Card::Tc, Card::Js);
    EXPECT_EQ("JsTc", reka6.show());
    Hand reka7(Card::Td, Card::Qh);
    EXPECT_EQ("QhTd", reka7.show());
    Hand reka8(Card::Qd, Card::Th);
    EXPECT_EQ("QdTh", reka8.show());
    Hand reka9(Card::Jh, Card::Jd);
    EXPECT_EQ("JhJd", reka9.show());
}

TEST(HandTest, middleHandCreation)
{
    Hand reka(Card::NineC, Card::NineS);
    EXPECT_EQ("9s9c", reka.show());
    Hand reka1(Card::NineD, Card::NineH);
    EXPECT_EQ("9h9d", reka1.show());
    Hand reka2(Card::EightC, Card::EightS);
    EXPECT_EQ("8s8c", reka2.show());
    Hand reka3(Card::EightH, Card::EightD);
    EXPECT_EQ("8h8d", reka3.show());
    Hand reka4(Card::SevenC, Card::SevenS);
    EXPECT_EQ("7s7c", reka4.show());
    Hand reka5(Card::SevenH, Card::SevenD);
    EXPECT_EQ("7h7d", reka5.show());
    Hand reka6(Card::SixC, Card::SixS);
    EXPECT_EQ("6s6c", reka6.show());
    Hand reka7(Card::SixD, Card::SixH);
    EXPECT_EQ("6h6d", reka7.show());
}

TEST(HandTest, lowHandCreation)
{
    Hand reka(Card::TwoC, Card::TwoS);
    EXPECT_EQ("2s2c", reka.show());
    Hand reka1(Card::TwoD, Card::TwoH);
    EXPECT_EQ("2h2d", reka1.show());
    Hand reka2(Card::ThreeC, Card::ThreeS);
    EXPECT_EQ("3s3c", reka2.show());
    Hand reka3(Card::ThreeH, Card::ThreeD);
    EXPECT_EQ("3h3d", reka3.show());
    Hand reka4(Card::FourC, Card::FourS);
    EXPECT_EQ("4s4c", reka4.show());
    Hand reka5(Card::FourD, Card::FourH);
    EXPECT_EQ("4h4d", reka5.show());
    Hand reka6(Card::FiveC, Card::FiveS);
    EXPECT_EQ("5s5c", reka6.show());
    Hand reka7(Card::FiveH, Card::FiveD);
    EXPECT_EQ("5h5d", reka7.show());
}

TEST(HandTest, HandOperatorEqual)
{
    Hand reka(Card::TwoC, Card::TwoS);
    Hand reka1(Card::TwoD, Card::TwoH);
    EXPECT_TRUE(reka1 == reka);
    Hand reka2(Card::Ah, Card::Kd);
    Hand reka3(Card::As, Card::Qc);
    EXPECT_FALSE(reka2 == reka3);
    Hand reka4(Card::Tc, Card::FiveH);
    Hand reka5(Card::Td, Card::FiveD);
    EXPECT_TRUE(reka4 == reka5);
}

TEST(HandTest, HandOperatorLess)
{
    Hand reka(Card::TwoC, Card::TwoS);
    Hand reka1(Card::TwoD, Card::TwoH);
    EXPECT_TRUE(reka < reka1);
    Hand reka2(Card::Ah, Card::Kd);
    Hand reka3(Card::As, Card::Qc);
    EXPECT_TRUE(reka3 < reka2);
    Hand reka4(Card::Tc, Card::FiveH);
    Hand reka5(Card::EightS, Card::FourH);
    EXPECT_TRUE(reka5 < reka4);
}
