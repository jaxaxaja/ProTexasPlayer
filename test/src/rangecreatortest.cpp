#include <gtest/gtest.h>
#include <strategy/range/RangeCreator.h>

TEST(RangeCreatorTest, Pairs)
{
    RangeCreator rc;
    Range range;
    EXPECT_TRUE(range.insert(Hand(Card::As, Card::Ah)));
    EXPECT_TRUE(range.insert(Hand(Card::As, Card::Ad)));
    EXPECT_TRUE(range.insert(Hand(Card::As, Card::Ac)));
    EXPECT_TRUE(range.insert(Hand(Card::Ah, Card::Ad)));
    EXPECT_TRUE(range.insert(Hand(Card::Ah, Card::Ac)));
    EXPECT_TRUE(range.insert(Hand(Card::Ad, Card::Ac)));
    EXPECT_TRUE(range.isInRange(Hand(Card::As, Card::Ah)));
    EXPECT_TRUE(range.isInRange(Hand(Card::As, Card::Ad)));
    EXPECT_TRUE(range.isInRange(Hand(Card::As, Card::Ac)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ah, Card::Ad)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ah, Card::Ac)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ad, Card::Ac)));
    EXPECT_EQ(6, range.combinations());

    Range range2;
    EXPECT_NO_THROW(range2 = rc.createRange("KK+"));
    EXPECT_EQ(12, range2.combinations());

    Range range3;
    EXPECT_NO_THROW(range3 = rc.createRange("TT+"));
    EXPECT_EQ(30, range3.combinations());

    Range range4;
    EXPECT_NO_THROW(range4 = rc.createRange("22+"));
    EXPECT_EQ(78, range4.combinations());
}

TEST(RangeCreatorTest, OffAndSuites)
{
    RangeCreator rc;
    Range range;
    EXPECT_NO_THROW(range = rc.createRange("AQo"));
    EXPECT_EQ(12, range.combinations());
    EXPECT_TRUE(range.isInRange(Hand(Card::As, Card::Qc)));
    EXPECT_TRUE(range.isInRange(Hand(Card::As, Card::Qh)));
    EXPECT_TRUE(range.isInRange(Hand(Card::As, Card::Qd)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ad, Card::Qs)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ad, Card::Qh)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ad, Card::Qc)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ah, Card::Qs)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ah, Card::Qc)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ah, Card::Qd)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ac, Card::Qs)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ac, Card::Qh)));
    EXPECT_TRUE(range.isInRange(Hand(Card::Ac, Card::Qd)));

    Range range2;
    EXPECT_NO_THROW(range2 = rc.createRange("KTo"));
    EXPECT_EQ(12, range2.combinations());
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Tc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Th)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Td)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Ts)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Th)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Tc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Ts)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Tc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Td)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Ts)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Th)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Td)));

    Range range3;
    EXPECT_NO_THROW(range3 = rc.createRange("72o"));
    EXPECT_EQ(12, range3.combinations());

    Range range4;
    EXPECT_NO_THROW(range4 = rc.createRange("32o"));
    EXPECT_EQ(12, range4.combinations());

    Range range5;
    EXPECT_NO_THROW(range5 = rc.createRange("JTs"));
    EXPECT_EQ(4, range5.combinations());
    EXPECT_TRUE(range5.isInRange(Hand(Card::Js, Card::Ts)));
    EXPECT_TRUE(range5.isInRange(Hand(Card::Jc, Card::Tc)));
    EXPECT_TRUE(range5.isInRange(Hand(Card::Jh, Card::Th)));
    EXPECT_TRUE(range5.isInRange(Hand(Card::Jd, Card::Td)));

    Range range6;
    EXPECT_NO_THROW(range6 = rc.createRange("78s"));
    EXPECT_EQ(4, range6.combinations());
    EXPECT_TRUE(range6.isInRange(Hand(Card::EightS, Card::SevenS)));
    EXPECT_TRUE(range6.isInRange(Hand(Card::EightC, Card::SevenC)));
    EXPECT_TRUE(range6.isInRange(Hand(Card::EightH, Card::SevenH)));
    EXPECT_TRUE(range6.isInRange(Hand(Card::EightD, Card::SevenD)));

    Range range7;
    EXPECT_NO_THROW(range7 = rc.createRange("AKs"));
    EXPECT_EQ(4, range7.combinations());

    Range range8;
    EXPECT_NO_THROW(range8 = rc.createRange("54s"));
    EXPECT_EQ(4, range8.combinations());
}

TEST(RangeCreatorTest, Combos)
{
    RangeCreator rc;
    Range range;
    EXPECT_NO_THROW(range = rc.createRange("JT+"));
    EXPECT_EQ(4*16+3*16+2*16+16, range.combinations());

    Range range2;
    EXPECT_NO_THROW(range2 = rc.createRange("KQ+"));
    EXPECT_EQ(48, range2.combinations());
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ks, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kh, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kd, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Kc, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Qs)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Qc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Qh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Qd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Ks)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Kc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Kh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::As, Card::Kd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Ks)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Kc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Kh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ah, Card::Kd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Ks)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Kc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Kh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ad, Card::Kd)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Ks)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Kc)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Kh)));
    EXPECT_TRUE(range2.isInRange(Hand(Card::Ac, Card::Kd)));
}

TEST(RangeCreatorTest, VariousCombinations)
{
    RangeCreator rc;
    Range range;
    EXPECT_NO_THROW(range = rc.createRange("AQo,TT+,JTs"));
    EXPECT_EQ(46, range.combinations());

    Range range2;
    EXPECT_NO_THROW(range2 = rc.createRange("JTo,22+,87s,T9s,89s"));
    EXPECT_EQ(102, range2.combinations());

    Range range3;
    EXPECT_NO_THROW(range3 = rc.createRange("KQ+,88+,45s"));
    EXPECT_EQ(94, range3.combinations());
}
