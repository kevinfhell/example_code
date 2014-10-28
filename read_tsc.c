typedef unsigned long long u64;
typedef  unsigned int u32;

static inline u64 read_tsc()
{
    union {
        u64 tsc_64;
        struct {
            u32 lo_32;
            u32 hi_32;
        };
    }tsc;
    asm volatile(
            "rdtsc":
            "=a"(tsc.lo_32),
            "=d"(tsc.hi_32)
            );
    return tsc.tsc_64;
}

