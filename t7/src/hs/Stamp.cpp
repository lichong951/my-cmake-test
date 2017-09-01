#include <Stamp.hpp>
#include <hs/HighResolutionClock.hpp>   // hs::HighResolutionClock
#include <hs/Burn.hpp>                  // hs::burnMs
#include <iostream>                     // std::cout

namespace
{
    void processing(size_t milliseconds)
    {
        hs::burnMs(milliseconds);
    }
}

TEST(Stamp, stamp_usage)
{
    hs::Timestamp begin = hs::stamp();
    processing(2);  // 2 milliseconds
    hs::Timestamp end = hs::stamp();

    EXPECT_GE(end - begin, 1000000);   // >= 1000000 ns.
}

TEST(Stamp, stampNs_usage)
{
    hs::Timestamp begin = hs::stampNs();
    processing(2);  // 2 milliseconds
    hs::Timestamp end = hs::stampNs();

    EXPECT_GE(end - begin, 1000000);   // >= 1000000 ns.
}

TEST(Stamp, stampUs_usage)
{
    hs::Timestamp begin = hs::stampUs();
    processing(2);  // 2 milliseconds
    hs::Timestamp end = hs::stampUs();

    EXPECT_GE(end - begin, 1000);   // >= 1000 us.
}

TEST(Stamp, stampMs_usage)
{
    hs::Timestamp begin = hs::stampMs();
    processing(2);  // 2 milliseconds
    hs::Timestamp end = hs::stampMs();

    EXPECT_GE(end - begin, 1);   // >= 1 ms.
}

TEST(Stamp, resolution)
{
    size_t tries = 50;

    std::cout << "time stamp resolution:" << std::endl;
    std::cout << "  stamp   = " << hs::measureStampEmpiricalResolution(hs::stamp, tries) << " ns" << std::endl;
    std::cout << "  stampNs = " << hs::measureStampEmpiricalResolution(hs::stampNs, tries) << " ns" << std::endl;
    std::cout << "  stampUs = " << hs::measureStampEmpiricalResolution(hs::stampUs, tries) << " us" << std::endl;
    std::cout << "  stampMs = " << hs::measureStampEmpiricalResolution(hs::stampMs, tries) << " ms" << std::endl;
}