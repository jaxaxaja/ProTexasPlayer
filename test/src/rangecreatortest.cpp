#include <gtest/gtest.h>
#include <strategy/range/RangeCreator.h>

TEST(RangeCreatorTest, Pairs)
{
    try {
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
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}

TEST(RangeCreatorTest, OffAndSuites)
{
    try {
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
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}

TEST(RangeCreatorTest, Combos)
{
    try {
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
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}

TEST(RangeCreatorTest, VariousCombinations)
{
    try {
        RangeCreator rc;
        Range range;
        EXPECT_NO_THROW(range = rc.createRange("AQo,TT+,JTs"));
        EXPECT_EQ(46, range.combinations());

        Range range1;
        EXPECT_NO_THROW(range1 = rc.createRange("32+,22+"));
        EXPECT_EQ(1326, range1.combinations());

        Range range2;
        EXPECT_NO_THROW(range2 = rc.createRange("JTo,22+,87s,T9s,89s"));
        EXPECT_EQ(102, range2.combinations());

        Range range3;
        EXPECT_NO_THROW(range3 = rc.createRange("KQ+,88+,45s"));
        EXPECT_EQ(94, range3.combinations());

        Range range4;
        EXPECT_NO_THROW(range4 = rc.createRange("KQ+,AJ+"));
        EXPECT_EQ(64, range4.combinations());

        Range range5;
        EXPECT_NO_THROW(range5 = rc.createRange("AJ+,ATs,A5s,A4s,A3s,A2s,KQ+,KJs,66+,T9s,98s"));
        EXPECT_EQ(150, range5.combinations());

        Range range6;
        EXPECT_NO_THROW(range6 = rc.createRange("AT+,A5s,A4s,A3s,A2s,KJ+,KTs,QJs,55+,JTs,T9s,98s,87s,76s"));
        EXPECT_EQ(200, range6.combinations());

        Range range7;
        EXPECT_NO_THROW(range7 = rc.createRange("A8+,A7s,A6s,A5s,A4s,A3s,A2s,KT+,K9s,QT+,Q9s,22+,JTs,J9s,T9s,"
                                                "T8s,98s,97s,87s,86s,76s,75s,65s,64s,54s"));
        EXPECT_EQ(338, range7.combinations());

        Range range8;
        EXPECT_NO_THROW(range8 = rc.createRange("A2+,K8+,K7s,K6s,Q9+,Q8s,Q7s,22+,JTs,J9s,J8s,J7s,T9s,T8s,T7s,"
                                                "98s,97s,96s,87s,86s,85s,76s,75s,74s,65s,64s,54s,53s,43s,42s,32s"));
        EXPECT_EQ(506, range8.combinations());
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        FAIL();
    }
}
