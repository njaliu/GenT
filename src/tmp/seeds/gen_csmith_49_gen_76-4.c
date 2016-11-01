extern int printf(const char *, ...);
static char safe_unary_minus_func_int8_t_s(char si)
{
  return si == (-128) ? si : -si;
}

static char safe_add_func_int8_t_s_s(char si1, char si2)
{
  return (((si1 > 0) && (si2 > 0)) && (si1 > (127 - si2))) || (((si1 < 0) && (si2 < 0)) && (si1 < ((-128) - si2))) ? si1 : si1 + si2;
}

static char safe_sub_func_int8_t_s_s(char si1, char si2)
{
  return ((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~127))) - si2) ^ si2)) < 0 ? si1 : si1 - si2;
}

static char safe_mul_func_int8_t_s_s(char si1, char si2)
{
  return (((((si1 > 0) && (si2 > 0)) && (si1 > (127 / si2))) || (((si1 > 0) && (si2 <= 0)) && (si2 < ((-128) / si1)))) || (((si1 <= 0) && (si2 > 0)) && (si1 < ((-128) / si2)))) || ((((si1 <= 0) && (si2 <= 0)) && (si1 != 0)) && (si2 < (127 / si1))) ? si1 : si1 * si2;
}

static char safe_mod_func_int8_t_s_s(char si1, char si2)
{
  return (si2 == 0) || ((si1 == (-128)) && (si2 == (-1))) ? si1 : si1 % si2;
}

static char safe_div_func_int8_t_s_s(char si1, char si2)
{
  return (si2 == 0) || ((si1 == (-128)) && (si2 == (-1))) ? si1 : si1 / si2;
}

static char safe_lshift_func_int8_t_s_s(char left, int right)
{
  return (((left < 0) || (((int) right) < 0)) || (((int) right) >= 32)) || (left > (127 >> ((int) right))) ? left : left << ((int) right);
}

static char safe_lshift_func_int8_t_s_u(char left, unsigned int right)
{
  return ((left < 0) || (((unsigned int) right) >= 32)) || (left > (127 >> ((unsigned int) right))) ? left : left << ((unsigned int) right);
}

static char safe_rshift_func_int8_t_s_s(char left, int right)
{
  return ((left < 0) || (((int) right) < 0)) || (((int) right) >= 32) ? left : left >> ((int) right);
}

static char safe_rshift_func_int8_t_s_u(char left, unsigned int right)
{
  return (left < 0) || (((unsigned int) right) >= 32) ? left : left >> ((unsigned int) right);
}

static short safe_unary_minus_func_int16_t_s(short si)
{
  return si == ((-32767) - 1) ? si : -si;
}

static short safe_add_func_int16_t_s_s(short si1, short si2)
{
  return (((si1 > 0) && (si2 > 0)) && (si1 > (32767 - si2))) || (((si1 < 0) && (si2 < 0)) && (si1 < (((-32767) - 1) - si2))) ? si1 : si1 + si2;
}

static short safe_sub_func_int16_t_s_s(short si1, short si2)
{
  return ((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~32767))) - si2) ^ si2)) < 0 ? si1 : si1 - si2;
}

static short safe_mul_func_int16_t_s_s(short si1, short si2)
{
  return (((((si1 > 0) && (si2 > 0)) && (si1 > (32767 / si2))) || (((si1 > 0) && (si2 <= 0)) && (si2 < (((-32767) - 1) / si1)))) || (((si1 <= 0) && (si2 > 0)) && (si1 < (((-32767) - 1) / si2)))) || ((((si1 <= 0) && (si2 <= 0)) && (si1 != 0)) && (si2 < (32767 / si1))) ? si1 : si1 * si2;
}

static short safe_mod_func_int16_t_s_s(short si1, short si2)
{
  return (si2 == 0) || ((si1 == ((-32767) - 1)) && (si2 == (-1))) ? si1 : si1 % si2;
}

static short safe_div_func_int16_t_s_s(short si1, short si2)
{
  return (si2 == 0) || ((si1 == ((-32767) - 1)) && (si2 == (-1))) ? si1 : si1 / si2;
}

static short safe_lshift_func_int16_t_s_s(short left, int right)
{
  return (((left < 0) || (((int) right) < 0)) || (((int) right) >= 32)) || (left > (32767 >> ((int) right))) ? left : left << ((int) right);
}

static short safe_lshift_func_int16_t_s_u(short left, unsigned int right)
{
  return ((left < 0) || (((unsigned int) right) >= 32)) || (left > (32767 >> ((unsigned int) right))) ? left : left << ((unsigned int) right);
}

static short safe_rshift_func_int16_t_s_s(short left, int right)
{
  return ((left < 0) || (((int) right) < 0)) || (((int) right) >= 32) ? left : left >> ((int) right);
}

static short safe_rshift_func_int16_t_s_u(short left, unsigned int right)
{
  return (left < 0) || (((unsigned int) right) >= 32) ? left : left >> ((unsigned int) right);
}

static int safe_unary_minus_func_int32_t_s(int si)
{
  return si == ((-2147483647) - 1) ? si : -si;
}

static int safe_add_func_int32_t_s_s(int si1, int si2)
{
  return (((si1 > 0) && (si2 > 0)) && (si1 > (2147483647 - si2))) || (((si1 < 0) && (si2 < 0)) && (si1 < (((-2147483647) - 1) - si2))) ? si1 : si1 + si2;
}

static int safe_sub_func_int32_t_s_s(int si1, int si2)
{
  return ((si1 ^ si2) & (((si1 ^ ((si1 ^ si2) & (~2147483647))) - si2) ^ si2)) < 0 ? si1 : si1 - si2;
}

static int safe_mul_func_int32_t_s_s(int si1, int si2)
{
  return (((((si1 > 0) && (si2 > 0)) && (si1 > (2147483647 / si2))) || (((si1 > 0) && (si2 <= 0)) && (si2 < (((-2147483647) - 1) / si1)))) || (((si1 <= 0) && (si2 > 0)) && (si1 < (((-2147483647) - 1) / si2)))) || ((((si1 <= 0) && (si2 <= 0)) && (si1 != 0)) && (si2 < (2147483647 / si1))) ? si1 : si1 * si2;
}

static int safe_mod_func_int32_t_s_s(int si1, int si2)
{
  return (si2 == 0) || ((si1 == ((-2147483647) - 1)) && (si2 == (-1))) ? si1 : si1 % si2;
}

static int safe_div_func_int32_t_s_s(int si1, int si2)
{
  return (si2 == 0) || ((si1 == ((-2147483647) - 1)) && (si2 == (-1))) ? si1 : si1 / si2;
}

static int safe_lshift_func_int32_t_s_s(int left, int right)
{
  return (((left < 0) || (((int) right) < 0)) || (((int) right) >= 32)) || (left > (2147483647 >> ((int) right))) ? left : left << ((int) right);
}

static int safe_lshift_func_int32_t_s_u(int left, unsigned int right)
{
  return ((left < 0) || (((unsigned int) right) >= 32)) || (left > (2147483647 >> ((unsigned int) right))) ? left : left << ((unsigned int) right);
}

static int safe_rshift_func_int32_t_s_s(int left, int right)
{
  return ((left < 0) || (((int) right) < 0)) || (((int) right) >= 32) ? left : left >> ((int) right);
}

static int safe_rshift_func_int32_t_s_u(int left, unsigned int right)
{
  return (left < 0) || (((unsigned int) right) >= 32) ? left : left >> ((unsigned int) right);
}

static unsigned char safe_unary_minus_func_uint8_t_u(unsigned char ui)
{
  return -ui;
}

static unsigned char safe_add_func_uint8_t_u_u(unsigned char ui1, unsigned char ui2)
{
  return ui1 + ui2;
}

static unsigned char safe_sub_func_uint8_t_u_u(unsigned char ui1, unsigned char ui2)
{
  return ui1 - ui2;
}

static unsigned char safe_mul_func_uint8_t_u_u(unsigned char ui1, unsigned char ui2)
{
  return ((unsigned int) ui1) * ((unsigned int) ui2);
}

static unsigned char safe_mod_func_uint8_t_u_u(unsigned char ui1, unsigned char ui2)
{
  return ui2 == 0 ? ui1 : ui1 % ui2;
}

static unsigned char safe_div_func_uint8_t_u_u(unsigned char ui1, unsigned char ui2)
{
  return ui2 == 0 ? ui1 : ui1 / ui2;
}

static unsigned char safe_lshift_func_uint8_t_u_s(unsigned char left, int right)
{
  return ((((int) right) < 0) || (((int) right) >= 32)) || (left > (255 >> ((int) right))) ? left : left << ((int) right);
}

static unsigned char safe_lshift_func_uint8_t_u_u(unsigned char left, unsigned int right)
{
  return (((unsigned int) right) >= 32) || (left > (255 >> ((unsigned int) right))) ? left : left << ((unsigned int) right);
}

static unsigned char safe_rshift_func_uint8_t_u_s(unsigned char left, int right)
{
  return (((int) right) < 0) || (((int) right) >= 32) ? left : left >> ((int) right);
}

static unsigned char safe_rshift_func_uint8_t_u_u(unsigned char left, unsigned int right)
{
  return ((unsigned int) right) >= 32 ? left : left >> ((unsigned int) right);
}

static unsigned short safe_unary_minus_func_uint16_t_u(unsigned short ui)
{
  return -ui;
}

static unsigned short safe_add_func_uint16_t_u_u(unsigned short ui1, unsigned short ui2)
{
  return ui1 + ui2;
}

static unsigned short safe_sub_func_uint16_t_u_u(unsigned short ui1, unsigned short ui2)
{
  return ui1 - ui2;
}

static unsigned short safe_mul_func_uint16_t_u_u(unsigned short ui1, unsigned short ui2)
{
  return ((unsigned int) ui1) * ((unsigned int) ui2);
}

static unsigned short safe_mod_func_uint16_t_u_u(unsigned short ui1, unsigned short ui2)
{
  return ui2 == 0 ? ui1 : ui1 % ui2;
}

static unsigned short safe_div_func_uint16_t_u_u(unsigned short ui1, unsigned short ui2)
{
  return ui2 == 0 ? ui1 : ui1 / ui2;
}

static unsigned short safe_lshift_func_uint16_t_u_s(unsigned short left, int right)
{
  return ((((int) right) < 0) || (((int) right) >= 32)) || (left > (65535 >> ((int) right))) ? left : left << ((int) right);
}

static unsigned short safe_lshift_func_uint16_t_u_u(unsigned short left, unsigned int right)
{
  return (((unsigned int) right) >= 32) || (left > (65535 >> ((unsigned int) right))) ? left : left << ((unsigned int) right);
}

static unsigned short safe_rshift_func_uint16_t_u_s(unsigned short left, int right)
{
  return (((int) right) < 0) || (((int) right) >= 32) ? left : left >> ((int) right);
}

static unsigned short safe_rshift_func_uint16_t_u_u(unsigned short left, unsigned int right)
{
  return ((unsigned int) right) >= 32 ? left : left >> ((unsigned int) right);
}

static unsigned safe_unary_minus_func_uint32_t_u(unsigned ui)
{
  return -ui;
}

static unsigned safe_add_func_uint32_t_u_u(unsigned ui1, unsigned ui2)
{
  return ui1 + ui2;
}

static unsigned safe_sub_func_uint32_t_u_u(unsigned ui1, unsigned ui2)
{
  return ui1 - ui2;
}

static unsigned safe_mul_func_uint32_t_u_u(unsigned ui1, unsigned ui2)
{
  return ((unsigned int) ui1) * ((unsigned int) ui2);
}

static unsigned safe_mod_func_uint32_t_u_u(unsigned ui1, unsigned ui2)
{
  return ui2 == 0 ? ui1 : ui1 % ui2;
}

static unsigned safe_div_func_uint32_t_u_u(unsigned ui1, unsigned ui2)
{
  return ui2 == 0 ? ui1 : ui1 / ui2;
}

static unsigned safe_lshift_func_uint32_t_u_s(unsigned left, int right)
{
  return ((((int) right) < 0) || (((int) right) >= 32)) || (left > (4294967295U >> ((int) right))) ? left : left << ((int) right);
}

static unsigned safe_lshift_func_uint32_t_u_u(unsigned left, unsigned int right)
{
  return (((unsigned int) right) >= 32) || (left > (4294967295U >> ((unsigned int) right))) ? left : left << ((unsigned int) right);
}

static unsigned safe_rshift_func_uint32_t_u_s(unsigned left, int right)
{
  return (((int) right) < 0) || (((int) right) >= 32) ? left : left >> ((int) right);
}

static unsigned safe_rshift_func_uint32_t_u_u(unsigned left, unsigned int right)
{
  return ((unsigned int) right) >= 32 ? left : left >> ((unsigned int) right);
}

static float safe_add_func_float_f_f(float sf1, float sf2)
{
  return fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282347e+38F) ? sf1 : sf1 + sf2;
}

static float safe_sub_func_float_f_f(float sf1, float sf2)
{
  return fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282347e+38F) ? sf1 : sf1 - sf2;
}

static float safe_mul_func_float_f_f(float sf1, float sf2)
{
  return fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * 3.40282347e+38F)) ? sf1 : sf1 * sf2;
}

static float safe_div_func_float_f_f(float sf1, float sf2)
{
  return (fabsf(sf2) < 1.0f) && ((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2)) > (0x1.0p-100f * (0x1.0p-49f * 3.40282347e+38F)))) ? sf1 : sf1 / sf2;
}

static double safe_add_func_double_f_f(double sf1, double sf2)
{
  return fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * 1.7976931348623158e+308) ? sf1 : sf1 + sf2;
}

static double safe_sub_func_double_f_f(double sf1, double sf2)
{
  return fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * 1.7976931348623158e+308) ? sf1 : sf1 - sf2;
}

static double safe_mul_func_double_f_f(double sf1, double sf2)
{
  return fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * 1.7976931348623158e+308)) ? sf1 : sf1 * sf2;
}

static double safe_div_func_double_f_f(double sf1, double sf2)
{
  return (fabs(sf2) < 1.0) && ((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2)) > (0x1.0p-100 * (0x1.0p-974 * 1.7976931348623158e+308)))) ? sf1 : sf1 / sf2;
}

static int safe_convert_func_float_to_int32_t(float sf1)
{
  return (sf1 <= ((-2147483647) - 1)) || (sf1 >= 2147483647) ? 2147483647 : (int) sf1;
}

inline static void platform_main_begin(void)
{
}

inline static void crc32_gentab(void)
{
}

unsigned long long crc32_context;
extern int strcmp(const char *, const char *);
inline static void transparent_crc(unsigned long long val, char *vname, int flag)
{
  if (flag)
    printf("%s %d\n", vname, val);

  crc32_context += val;
}

static void transparent_crc_bytes(char *ptr, int nbytes, char *vname, int flag)
{
  int i;
  for (i = 0; i < nbytes; i++)
  {
    crc32_context += ptr[i];
  }

  if (flag)
  {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
  }

}

inline static void platform_main_end(unsigned long long x, int flag)
{
  if (!flag)
  {
    printf("checksum = %llx\n", x);
  }

}

volatile unsigned csmith_sink_ = 0;
static long __undefined;
struct S0
{
  short f0;
  volatile int f1;
  unsigned short f2;
  unsigned f3;
  unsigned short f4;
  volatile int f5;
};
struct S1
{
  volatile int f0;
  int f1;
  volatile int f2;
  unsigned short f3;
  int f4;
};
union U2
{
  volatile short f0;
  volatile struct S0 f1;
};
union U3
{
  int f0;
};
static volatile short g_13 = 0xF793L;
static int g_18 = 0x4FB389FAL;
static unsigned short g_64 = 0x5ED1L;
static short g_65[3] = {0xBBB0L, 0xBBB0L, 0xBBB0L};
static int *g_81 = &g_18;
static struct S0 g_84 = {0x3D8BL, 0L, 0xF9F9L, 4UL, 0x5852L, 0x62AA9168L};
static struct S0 *g_86 = &g_84;
static volatile struct S0 g_89 = {0x49D4L, 0xBAF9760DL, 1UL, 0xCB904F0DL, 0x0DC8L, 0x9B9F5A9AL};
static volatile struct S0 g_90 = {0x3D43L, -7L, 0x5AD6L, 0UL, 0x3228L, 1L};
static struct S0 g_91 = {0xCD10L, 0xC4FFD0F0L, 0x4999L, 9UL, 0xA79BL, -1L};
static struct S0 g_118[4] = {{-6L, 0xD90F720CL, 2UL, 2UL, 0UL, -1L}, {-6L, 0xD90F720CL, 2UL, 2UL, 0UL, -1L}, {-6L, 0xD90F720CL, 2UL, 2UL, 0UL, -1L}, {-6L, 0xD90F720CL, 2UL, 2UL, 0UL, -1L}};
static union U2 g_122 = {0xF1E6L};
static union U2 g_123[6] = {{-7L}, {-7L}, {1L}, {-7L}, {-7L}, {1L}};
static struct S1 g_137 = {0x67C8C73FL, 0x52EA5237L, 1L, 65535UL, 1L};
static struct S1 g_175 = {0x51025D35L, 0x0CBF2326L, 0xE939A098L, 1UL, 0x580385B4L};
static volatile union U3 g_180[10][8] = {{{8L}, {0x8E61B92BL}, {4L}, {0xE769F5B5L}, {1L}, {-1L}, {8L}, {0L}}, {{1L}, {0x76FBAC7AL}, {-1L}, {0x98519613L}, {0x8FA4D6DCL}, {0x4E2784B6L}, {0x4E2784B6L}, {0x8FA4D6DCL}}, {{0x5C80A1DAL}, {-1L}, {-1L}, {0x5C80A1DAL}, {-5L}, {-1L}, {0L}, {0x4E2784B6L}}, {{0x8E61B92BL}, {3L}, {0xBD8DA2AAL}, {0x8FA4D6DCL}, {1L}, {1L}, {8L}, {3L}}, {{-1L}, {-1L}, {1L}, {0x1AFC666AL}, {5L}, {-1L}, {0x6CF05B78L}, {-1L}}, {{-5L}, {-4L}, {0L}, {-1L}, {-4L}, {1L}, {-1L}, {2L}}, {{0x721E7CADL}, {-1L}, {0x8FA4D6DCL}, {1L}, {-6L}, {0x1B1E4525L}, {-6L}, {1L}}, {{0x1AFC666AL}, {0x98519613L}, {0x1AFC666AL}, {-1L}, {-5L}, {0L}, {0xBD8DA2AAL}, {0x63417869L}}, {{-1L}, {1L}, {-4L}, {-1L}, {0L}, {-4L}, {-5L}, {0x6CF05B78L}}, {{-1L}, {1L}, {1L}, {-6L}, {-5L}, {-3L}, {0L}, {-1L}}};
static volatile union U3 *g_179 = &g_180[6][7];
static volatile union U3 **g_178 = &g_179;
static struct S0 func_1(void);
static int func_3(short p_4, int p_5, int p_6);
static unsigned short func_8(int p_9, int p_10);
static struct S0 func_1(void)
{
  short l_2 = 0x3948L;
  struct S0 **l_117 = &g_86;
  union U2 *l_134 = &g_122;
  int *l_140 = (void *) 0;
  int l_145 = -1L;
  if (l_2)
  {
    unsigned l_7[8][7] = {{4UL, 4294967291UL, 0x34111D01L, 0x7263B0A6L, 0xC42206DDL, 0x5BBBDEBFL, 0x8753E1E0L}, {0x5BBBDEBFL, 4294967294UL, 4UL, 0xF9986E3EL, 0x03C57643L, 0x8753E1E0L, 0x03C57643L}, {0xC42206DDL, 4294967291UL, 4294967291UL, 0xC42206DDL, 0x105FA2EFL, 0x7263B0A6L, 4294967286UL}, {0xC42206DDL, 0x8753E1E0L, 0x0811FC80L, 4294967294UL, 1UL, 0xB17D72B9L, 0x34111D01L}, {0x5BBBDEBFL, 0x105FA2EFL, 4294967286UL, 1UL, 4UL, 1UL, 4294967286UL}, {4UL, 4UL, 6UL, 8UL, 0xB17D72B9L, 1UL, 0x03C57643L}, {0xF9986E3EL, 6UL, 0x03C57643L, 4294967291UL, 0x5BBBDEBFL, 0xB17D72B9L, 0x8753E1E0L}, {1UL, 0x7263B0A6L, 0xB17D72B9L, 0x03C57643L, 0xB17D72B9L, 0x7263B0A6L, 1UL}};
    int i;
    int j;
    g_89.f5 = func_3(l_7[2][1], 0x1AF9L || (((((func_8(((int) ((g_13 & (((int) (((((((unsigned short) ((l_2 ^ (g_18 || (((unsigned short) ((((g_18 & (((g_18 == (-9L)) || (l_7[2][1] || l_2)) >= 0x042CL)) & l_7[3][4]) ^ 1L) && 0xA46BB218L)) << ((unsigned short) 13)))) & g_18)) >> ((unsigned short) 9)) & g_18) == 8L) != 0x76E8D2CAL) == 0UL)) - ((int) g_18))) >= g_18)) - ((int) g_18), l_2) == g_65[1]) || l_2) != g_65[1]) & l_7[2][1]) < 65535UL), g_65[1]);
  }
  else
  {
    union U3 *l_100 = (void *) 0;
    int l_114 = -1L;
    union U2 *l_121[9] = {&g_123[0], &g_123[0], &g_123[0], &g_123[0], &g_123[0], &g_123[0], &g_123[0], &g_123[0], &g_123[0]};
    struct S1 *l_136 = &g_137;
    int i;
    for (g_84.f3 = 0; g_84.f3 <= 2; g_84.f3 += 1)
    {
      union U3 **l_101 = &l_100;
      *l_101 = l_100;
      for (g_91.f3 = 0; g_91.f3 <= 2; g_91.f3 += 1)
      {
        int i;
        *g_81 = ((((int) (((((short) ((((unsigned short) ((((g_65[g_91.f3] && g_18) < ((((short) 0x2066L) >> ((short) (1L < (((short) (((unsigned short) l_114) - ((unsigned short) (((-((unsigned short) (0L && (~g_90.f1)))) | (l_117 == ((void *) 0))) || l_2)))) >> ((short) l_2))))) != g_84.f2)) & g_91.f2) ^ 0xF0CF8135L)) % ((unsigned short) l_114)) >= (*g_81))) << ((short) 12)) ^ (*g_81)) & g_65[g_91.f3])) - ((int) g_18)) >= g_65[g_91.f3]) <= g_84.f0;
        return g_118[1];
      }

    }

    if (g_89.f3 != ((((int) ((g_84.f4 || l_114) <= (((((((void *) 0) == l_121[1]) && ((((unsigned short) ((~g_91.f3) | ((&g_86) != ((void *) 0)))) >> ((unsigned short) g_118[1].f2)) || g_84.f2)) != l_2) ^ l_2) != g_65[1]))) % ((int) g_64)) | g_84.f0))
    {
      *g_81 = l_2;
    }
    else
    {
      unsigned l_131 = 0xD5FB0443L;
      for (g_84.f2 = 0; g_84.f2 < 31; g_84.f2 += 9)
      {
        if (1UL & (((short) l_131) % ((short) g_123[0].f0)))
        {
          for (g_91.f2 = -27; g_91.f2 < 7; g_91.f2 += 3)
          {
            union U2 **l_135 = &l_134;
            *l_135 = l_134;
          }

        }
        else
        {
          struct S1 **l_138 = &l_136;
          *l_138 = l_136;
        }

        if (*g_81)
          continue;

        for (g_91.f4 = 0; g_91.f4 <= 3; g_91.f4 += 1)
        {
          int *l_139 = &l_114;
          int l_141 = 0x9CB02FEDL;
          l_140 = l_139;
          *g_81 = l_141;
        }

      }

      for (g_18 = 8; g_18 >= 0; g_18 -= 1)
      {
        union U3 **l_142 = (void *) 0;
        union U3 **l_143 = &l_100;
        *l_143 = (void *) 0;
        for (g_91.f4 = 0; g_91.f4 <= 2; g_91.f4 += 1)
        {
          int l_176 = 0x2D15554DL;
          int **l_177 = &l_140;
          for (g_91.f3 = 0; g_91.f3 <= 8; g_91.f3 += 1)
          {
            int *l_144[5][6][3] = {{{&g_137.f1, &g_137.f1, &g_137.f4}, {&g_137.f1, &l_114, &g_18}, {&l_114, (void *) 0, &g_137.f1}, {&g_137.f4, &l_114, &g_137.f1}, {&g_137.f4, &g_137.f1, (void *) 0}, {(void *) 0, &g_137.f4, &g_137.f1}}, {{(void *) 0, &g_137.f1, &g_137.f1}, {(void *) 0, &g_137.f4, &g_137.f1}, {&g_137.f1, &g_18, &g_137.f1}, {&l_114, &g_18, (void *) 0}, {&g_137.f1, &g_137.f4, &g_137.f1}, {&l_114, &g_137.f4, &g_137.f1}}, {{&g_18, (void *) 0, &g_18}, {&l_114, &g_18, &g_137.f4}, {&g_137.f1, &g_137.f4, (void *) 0}, {&l_114, (void *) 0, &g_137.f1}, {&g_137.f1, &g_137.f1, &g_18}, {(void *) 0, &g_137.f1, &g_137.f4}}, {{(void *) 0, (void *) 0, &l_114}, {(void *) 0, &g_137.f4, (void *) 0}, {&g_137.f4, &g_18, &l_114}, {&g_137.f4, (void *) 0, &g_137.f4}, {&l_114, &g_137.f4, &l_114}, {&g_137.f1, &g_137.f4, (void *) 0}}, {{&g_137.f1, &g_18, &l_114}, {&g_18, &g_18, &g_137.f4}, {&l_114, &g_18, (void *) 0}, {&g_18, &g_137.f4, &g_137.f4}, {&g_18, &g_137.f1, (void *) 0}, {&g_137.f4, &g_137.f4, &l_114}}};
            struct S1 *l_174 = &g_175;
            int i;
            int j;
            int k;
            if (g_65[g_91.f4])
              break;

            l_145 = 0x7CF8A12AL;
            l_176 = ((short) (((unsigned short) (((unsigned short) (((int) (*g_81)) - ((int) (((short) (((((short) g_90.f5) - ((short) (((((unsigned) (((int) 0xF28E98AEL) + ((int) (((unsigned short) ((g_137.f4 ^ (((((short) (((unsigned short) g_84.f4) << ((unsigned short) 1))) % ((short) (((short) (((*g_81) >= (((unsigned short) (((l_174 != l_136) ^ 0UL) >= (*g_81))) >> ((unsigned short) 10))) || l_131)) << ((short) g_84.f3)))) != g_91.f3) < g_175.f3)) && g_118[1].f2)) + ((unsigned short) 0UL))))) % ((unsigned) (*g_81))) ^ g_118[1].f3) != l_176))) <= 0x83D3069CL) == l_114)) + ((short) 0L))))) + ((unsigned short) g_175.f4))) - ((unsigned short) 0x0142L))) + ((short) g_91.f4);
          }

          *l_177 = &l_145;
        }

      }

      *g_81 = g_178 == ((void *) 0);
    }

  }

  return g_90;
}

static int func_3(short p_4, int p_5, int p_6)
{
  short l_66 = 0xF4DEL;
  short l_77 = 0x713FL;
  if (l_66)
  {
    int *l_68 = &g_18;
    int **l_67 = &l_68;
    *l_67 = (void *) 0;
  }
  else
  {
    int *l_87 = &g_18;
    if (((int) (((unsigned short) p_4) >> ((unsigned short) 0))) % ((int) (((int) ((1L == 65529UL) ^ (((int) ((&p_6) == ((void *) 0))) + ((int) (((g_65[1] >= 65533UL) > (l_77 | (((int) 0xB757F9C6L) % ((int) 0xC73EBF55L)))) >= g_65[1]))))) + ((int) p_5))))
    {
      int **l_80[3];
      union U2 *l_82 = (void *) 0;
      int i;
      for (i = 0; i < 3; i = i + 1)
        l_80[i] = (void *) 0;

      g_81 = &p_6;
      l_82 = l_82;
    }
    else
    {
      int **l_88[5][8] = {{&g_81, &g_81, &g_81, &l_87, &l_87, &g_81, &g_81, &g_81}, {&g_81, &g_81, &g_81, &l_87, &l_87, &g_81, &g_81, &g_81}, {&g_81, &g_81, &g_81, &l_87, &l_87, &g_81, &g_81, &g_81}, {&g_81, &g_81, &g_81, &l_87, &l_87, &g_81, &g_81, &g_81}, {&g_81, &g_81, &g_81, &l_87, &l_87, &g_81, &g_81, &g_81}};
      int i;
      int j;
      for (l_66 = 2; l_66 >= 0; l_66 -= 1)
      {
        struct S0 *l_83[10][10] = {{&g_84, &g_84, &g_84, &g_84, &g_84, (void *) 0, (void *) 0, &g_84, &g_84, &g_84}, {&g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84}, {&g_84, (void *) 0, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, (void *) 0, &g_84}, {&g_84, &g_84, (void *) 0, &g_84, &g_84, &g_84, (void *) 0, &g_84, &g_84, &g_84}, {&g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84}, {&g_84, (void *) 0, &g_84, &g_84, &g_84, (void *) 0, &g_84, &g_84, &g_84, &g_84}, {&g_84, &g_84, &g_84, &g_84, &g_84, &g_84, (void *) 0, &g_84, (void *) 0, &g_84}, {&g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84}, {&g_84, (void *) 0, (void *) 0, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84, &g_84}, {&g_84, &g_84, &g_84, &g_84, &g_84, (void *) 0, (void *) 0, &g_84, &g_84, &g_84}};
        struct S0 **l_85[8] = {&l_83[9][0], &l_83[9][0], &l_83[9][0], &l_83[9][0], &l_83[9][0], &l_83[9][0], &l_83[9][0], &l_83[9][0]};
        int i;
        int j;
        g_86 = l_83[4][6];
        if (g_65[l_66])
          break;

      }

      g_81 = l_87;
    }

    g_90 = g_89;
  }

  g_91 = g_84;
  *g_81 = ((((4294967295UL || (1L || l_66)) >= ((((((short) (p_6 != 9UL)) - ((short) (((((unsigned short) l_77) - ((unsigned short) (((0x5C70L != (3L & (((unsigned) (((((short) ((g_89.f4 > l_77) < 0x3471L)) >> ((short) g_84.f0)) || (-4L)) && p_5)) % ((unsigned) l_66)))) || 0x678AA32FL) <= l_66))) || p_5) > 0xA868L))) && p_5) == l_66) == 0xDB709881L)) <= 0x956CL) ^ 0x11F2L) <= g_18;
  return l_77;
}

static unsigned short func_8(int p_9, int p_10)
{
  int l_38 = 0x93A78091L;
  int *l_39[5][7] = {{&g_18, &g_18, &g_18, &g_18, &g_18, &g_18, &g_18}, {&g_18, &g_18, &g_18, &g_18, &g_18, &g_18, &g_18}, {&g_18, &g_18, &g_18, &g_18, &g_18, &g_18, &g_18}, {&g_18, &g_18, &g_18, &g_18, &g_18, &g_18, &g_18}, {&g_18, &g_18, &g_18, &g_18, &g_18, &g_18, &g_18}};
  int *l_54 = &g_18;
  {
    ERROR:
    __VERIFIER_error();

    int i;
  }
  int j;
  p_10 = ((unsigned short) (((short) (p_10 && (p_10 < (((short) ((((g_13 <= p_10) || ((((((unsigned) ((p_10 >= 6L) != ((((((4294967292UL || (((((short) (~(((unsigned short) (1UL | ((((short) ((((unsigned short) p_9) % ((unsigned short) l_38)) > 0x399D6DB7L)) >> ((short) 9)) == l_38))) << ((unsigned short) p_10)))) << ((short) l_38)) == g_18) != p_10)) <= 3L) <= (-5L)) & g_13) != p_9) >= p_9))) + ((unsigned) g_18)) & 0x7DE48418L) <= 0x7A66L) == 0x2993L)) ^ 0x53AF4B50L) && 0x48012CFBL)) >> ((short) 9))))) + ((short) (-1L)))) << ((unsigned short) 5);
  l_39[4][0] = (void *) 0;
  for (g_18 = 0; g_18 > (-18); g_18 -= 1)
  {
    unsigned short l_61 = 0x9CA1L;
    p_10 = ((((int) (((short) p_9) >> ((short) (((short) (((((unsigned short) (((short) ((((short) ((((&g_18) == l_54) <= (((short) (((short) ((g_13 ^ ((p_10 < (g_18 == (((((short) l_61) >> ((short) 12)) > ((0L >= ((((int) l_61) % ((int) 0x5D6CF981L)) & g_18)) && p_9)) && p_9))) >= p_10)) >= g_18)) >> ((short) 3))) - ((short) 1L))) >= l_61)) << ((short) g_18)) > (*l_54))) << ((short) l_61))) % ((unsigned short) g_18)) ^ g_18) >= 5UL)) >> ((short) g_18))))) + ((int) 0x74787CBDL)) == (*l_54)) && (-1L);
    g_64 = (&g_18) == (&p_10);
  }

  return p_10;
}

int main(void)
{
  int i;
  int j;
  int print_hash_value = 0;
  platform_main_begin();
  func_1();
  csmith_sink_ = g_13;
  csmith_sink_ = g_18;
  csmith_sink_ = g_64;
  for (i = 0; i < 3; i = i + 1)
  {
    csmith_sink_ = g_65[i];
  }

  csmith_sink_ = g_84.f0;
  csmith_sink_ = g_84.f1;
  csmith_sink_ = g_84.f2;
  csmith_sink_ = g_84.f3;
  csmith_sink_ = g_84.f4;
  csmith_sink_ = g_84.f5;
  csmith_sink_ = g_89.f0;
  csmith_sink_ = g_89.f1;
  csmith_sink_ = g_89.f2;
  csmith_sink_ = g_89.f3;
  csmith_sink_ = g_89.f4;
  csmith_sink_ = g_89.f5;
  csmith_sink_ = g_90.f0;
  csmith_sink_ = g_90.f1;
  csmith_sink_ = g_90.f2;
  csmith_sink_ = g_90.f3;
  csmith_sink_ = g_90.f4;
  csmith_sink_ = g_90.f5;
  csmith_sink_ = g_91.f0;
  csmith_sink_ = g_91.f1;
  csmith_sink_ = g_91.f2;
  csmith_sink_ = g_91.f3;
  csmith_sink_ = g_91.f4;
  csmith_sink_ = g_91.f5;
  for (i = 0; i < 4; i = i + 1)
  {
  }

  csmith_sink_ = g_122.f0;
  for (i = 0; i < 6; i = i + 1)
  {
  }

  csmith_sink_ = g_137.f0;
  csmith_sink_ = g_137.f1;
  csmith_sink_ = g_137.f2;
  csmith_sink_ = g_137.f3;
  csmith_sink_ = g_137.f4;
  csmith_sink_ = g_175.f0;
  csmith_sink_ = g_175.f1;
  csmith_sink_ = g_175.f2;
  csmith_sink_ = g_175.f3;
  csmith_sink_ = g_175.f4;
  for (i = 0; i < 10; i = i + 1)
  {
    for (j = 0; j < 8; j = j + 1)
    {
    }

  }

  platform_main_end(0, 0);
  return 0;
}

