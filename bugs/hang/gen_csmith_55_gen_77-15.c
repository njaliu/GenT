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
  unsigned short f0;
  int f1;
  volatile unsigned short f2;
  volatile short f3;
  int f4;
  int f5;
  unsigned f6;
};
struct S1
{
  volatile unsigned f0;
  volatile int f1;
  unsigned f2;
};
struct S2
{
  unsigned short f0;
  unsigned short f1;
  struct S1 f2;
  unsigned short f3;
};
struct S3
{
  struct S0 f0;
  unsigned short f1;
  volatile struct S2 f2;
  int f3;
  unsigned short f4;
  unsigned f5;
};
struct S4
{
  volatile unsigned short f0;
  volatile struct S0 f1;
  volatile unsigned short f2;
  unsigned f3;
  unsigned f4;
  struct S1 f5;
  struct S0 f6;
  struct S2 f7;
};
struct S5
{
  short f0;
};
static struct S5 g_6 = {0x9683L};
static struct S4 g_17 = {0UL, {4UL, -3L, 0xD4AAL, -1L, 0x0D1C1D68L, 0xA37BD55FL, 0x0A3205F5L}, 0x2F61L, 0xA9413E45L, 1UL, {4294967288UL, 0x22A19820L, 9UL}, {65535UL, 6L, 1UL, -1L, 0x9EB11DE2L, -10L, 0x865E1BFEL}, {0xAACDL, 65535UL, {0xF2A6CA0CL, 0xC51938D1L, 0xFBF2B831L}, 65535UL}};
static struct S4 *g_16 = &g_17;
static struct S3 g_20 = {{65533UL, 0xEF7B6068L, 1UL, -1L, 0x52C43DA4L, 0xA2EEDF21L, 0x16DC91E8L}, 7UL, {65535UL, 0x2215L, {1UL, 0x4A9B53ABL, 0x6A420A61L}, 1UL}, 1L, 65535UL, 0x5A6F0ED5L};
static volatile int *g_56[8][1] = {{&g_17.f7.f2.f1}, {&g_20.f2.f2.f1}, {&g_17.f7.f2.f1}, {&g_20.f2.f2.f1}, {&g_17.f7.f2.f1}, {&g_20.f2.f2.f1}, {&g_17.f7.f2.f1}, {&g_20.f2.f2.f1}};
static volatile struct S4 g_90 = {1UL, {0UL, -1L, 65535UL, 0L, 0x7AB760D9L, 0x4AFFB0DCL, 0x7877F705L}, 0x7A70L, 4294967295UL, 0x5ECE1F0CL, {3UL, 2L, 0xBAF00BCFL}, {6UL, 0x0A4D05B2L, 65535UL, 0x25EAL, 0xA3312545L, 0xD931822BL, 4294967289UL}, {65535UL, 65535UL, {4294967295UL, 1L, 9UL}, 0x2C81L}};
static volatile struct S4 *g_89 = &g_90;
static volatile struct S4 **g_88[10][1] = {{&g_89}, {(void *) 0}, {&g_89}, {(void *) 0}, {&g_89}, {(void *) 0}, {&g_89}, {(void *) 0}, {&g_89}, {(void *) 0}};
static volatile struct S4 ***g_87 = &g_88[3][0];
static struct S0 g_106[6] = {{8UL, 0L, 5UL, 6L, 1L, 0xE450C1D2L, 6UL}, {8UL, 0L, 5UL, 6L, 1L, 0xE450C1D2L, 6UL}, {8UL, 0L, 5UL, 6L, 1L, 0xE450C1D2L, 6UL}, {8UL, 0L, 5UL, 6L, 1L, 0xE450C1D2L, 6UL}, {8UL, 0L, 5UL, 6L, 1L, 0xE450C1D2L, 6UL}, {8UL, 0L, 5UL, 6L, 1L, 0xE450C1D2L, 6UL}};
static struct S0 func_1(void);
static struct S4 *func_2(struct S5 p_3, unsigned p_4, int p_5);
static unsigned short func_10(int p_11, int p_12, struct S4 *p_13, unsigned p_14, struct S5 p_15);
static struct S0 func_1(void)
{
  int l_7 = -1L;
  struct S5 l_18[4][9][5] = {{{{0xCE99L}, {0L}, {0L}, {0x62E5L}, {-1L}}, {{0x3BF0L}, {0xB07DL}, {0xB07DL}, {0x3BF0L}, {0x4BB8L}}, {{0xCE99L}, {0x100FL}, {0L}, {0x86B4L}, {0x62E5L}}, {{0xB07DL}, {0xD29DL}, {-1L}, {2L}, {-1L}}, {{0xE19CL}, {0xE19CL}, {0xCE99L}, {1L}, {-1L}}, {{0x1871L}, {0x4BBCL}, {0xD29DL}, {2L}, {0x3BF0L}}, {{0x100FL}, {0xCE99L}, {1L}, {0xCE99L}, {0x100FL}}, {{0L}, {0x4BBCL}, {-1L}, {0L}, {0x4BB8L}}, {{1L}, {0x62E5L}, {0x57D8L}, {0L}, {0L}}}, {{{0L}, {0xCDAAL}, {0L}, {0x4BBCL}, {0x4BB8L}}, {{0L}, {0L}, {0x62E5L}, {0L}, {0x100FL}}, {{0x4BB8L}, {0x3BF0L}, {0xB07DL}, {0xB07DL}, {0x3BF0L}}, {{0x57D8L}, {0L}, {0x62E5L}, {0x100FL}, {-1L}}, {{0xCDAAL}, {0xCA19L}, {0L}, {0xD29DL}, {0x0C2DL}}, {{0xE19CL}, {0x57D8L}, {0x57D8L}, {0xE19CL}, {0xCE99L}}, {{0xCDAAL}, {0xB07DL}, {-1L}, {0L}, {0xD29DL}}, {{0x57D8L}, {0x86B4L}, {1L}, {0x62E5L}, {1L}}, {{0x4BB8L}, {0x4BB8L}, {0xD29DL}, {0L}, {-1L}}}, {{{0L}, {0L}, {0xCE99L}, {0xE19CL}, {0x57D8L}}, {{0L}, {0xD29DL}, {0x0C2DL}, {0xD29DL}, {0L}}, {{1L}, {0L}, {-1L}, {0x100FL}, {0x62E5L}}, {{0L}, {0x4BB8L}, {0x3BF0L}, {0xB07DL}, {0xB07DL}}, {{0x100FL}, {0x86B4L}, {0x100FL}, {0L}, {0x62E5L}}, {{0x1871L}, {0xB07DL}, {0x4BB8L}, {0x4BBCL}, {0L}}, {{0x62E5L}, {0x57D8L}, {0L}, {0L}, {0x57D8L}}, {{0x3BF0L}, {0xCA19L}, {0x4BB8L}, {0L}, {-1L}}, {{0x86B4L}, {0L}, {0x100FL}, {0xCE99L}, {1L}}}, {{{2L}, {0x3BF0L}, {0x3BF0L}, {2L}, {0xD29DL}}, {{0x86B4L}, {0L}, {-1L}, {1L}, {0xCE99L}}, {{0x3BF0L}, {0xCDAAL}, {0x0C2DL}, {0x4BB8L}, {0x0C2DL}}, {{0x62E5L}, {0x62E5L}, {0xCE99L}, {1L}, {-1L}}, {{0x1871L}, {0x4BBCL}, {0xD29DL}, {2L}, {0x3BF0L}}, {{0x100FL}, {0xCE99L}, {1L}, {0xCE99L}, {0x100FL}}, {{0L}, {0x4BBCL}, {-1L}, {0L}, {0x4BB8L}}, {{1L}, {0x62E5L}, {0x57D8L}, {0L}, {0L}}, {{0L}, {0xCDAAL}, {0L}, {0x4BBCL}, {0x4BB8L}}}};
  struct S4 **l_28 = &g_16;
  struct S3 *l_70 = &g_20;
  int l_103 = 7L;
  int i;
  int j;
  int k;
  *l_28 = func_2(g_6, l_7, g_6.f0 | (((unsigned short) func_10(g_6.f0, g_6.f0, g_16, g_17.f5.f2, l_18[1][0][4])) - ((unsigned short) l_7)));
  for (g_20.f5 = 0; g_20.f5 < 4; g_20.f5 += 1)
  {
    for (g_17.f1.f3 = 0; g_17.f1.f3 < 9; g_17.f1.f3 += 1)
    {
      for (g_20.f0.f2 = 0; g_20.f0.f2 < 5; g_20.f0.f2 += 1)
      {
        struct S5 tmp = {-9L};
        l_18[g_20.f5][g_17.f1.f3][g_20.f0.f2] = tmp;
      }

    }

  }

  if (g_17.f1.f4)
  {
    struct S3 *l_40 = &g_20;
    unsigned l_41 = 0x25F2AAF3L;
    int l_55[1];
    struct S4 *l_65 = &g_17;
    int i;
    for (i = 0; i < 1; i = i + 1)
      l_55[i] = 0x2B8DC093L;

    for (g_20.f0.f6 = 18; g_20.f0.f6 < 12; g_20.f0.f6 -= 6)
    {
      unsigned l_54 = 0x033C1528L;
      volatile int *l_57 = &g_17.f1.f5;
      l_55[0] = (((unsigned short) (!(((short) ((((((unsigned short) (((short) ((g_17.f7.f3 < (l_40 != l_40)) == l_41)) >> ((short) 2))) - ((unsigned short) ((((((int) (((unsigned short) ((l_41 & (((((short) g_17.f6.f0) >> ((short) (((((short) ((((unsigned short) (g_20.f2.f0 >= (g_17.f4 > ((((short) g_17.f4) >> ((short) 1)) == l_54)))) + ((unsigned short) g_17.f6.f6)) ^ 0UL)) >> ((short) g_17.f6.f0)) ^ g_17.f7.f2.f2) <= l_18[1][0][4].f0))) || g_20.f0.f0) != g_17.f6.f6)) == l_41)) << ((unsigned short) 15))) % ((int) l_41)) == l_7) > 6L) || l_54))) != l_7) ^ g_17.f4) & 0x687E89A4L)) << ((short) 14)))) - ((unsigned short) 0xBF99L)) && 0xC30CL;
      l_57 = g_56[3][0];
    }

    if (((int) (l_7 ^ ((-((short) ((((unsigned short) (((unsigned short) g_17.f7.f3) << ((unsigned short) 9))) << ((unsigned short) (l_55[0] ^ (((&g_17) == l_65) < (((short) (((((unsigned short) (((void *) 0) != l_70)) >> ((unsigned short) l_41)) != g_17.f5.f2) < 0L)) << ((short) l_55[0])))))) & l_18[1][0][4].f0))) <= g_17.f1.f2))) - ((int) 4294967292UL))
    {
      short l_71 = 4L;
      int *l_91 = &g_20.f0.f4;
      *l_91 = ((l_71 ^ 0L) <= (-((int) 0L))) & (-((int) (((unsigned short) (0xBC02L == (((unsigned short) (0xB465L != (~l_71))) % ((unsigned short) (((unsigned short) ((((short) ((((short) 1L) + ((short) (((((((short) (g_87 != (&g_88[3][0]))) << ((short) g_17.f6.f0)) > 0xC15FL) > (-8L)) || 1UL) & (-6L)))) | 0UL)) << ((short) g_20.f2.f2.f1)) ^ g_20.f0.f1)) + ((unsigned short) g_17.f7.f2.f2)))))) >> ((unsigned short) l_7))));
      *l_91 = *l_91;
      *l_91 = !(0x9D0EL ^ (((short) (-8L)) - ((short) (((unsigned short) l_18[1][0][4].f0) << ((unsigned short) 6)))));
    }
    else
    {
      int *l_104 = &l_55[0];
      *l_104 = ((((short) (g_17.f0 <= l_55[0])) << ((short) 1)) && l_18[1][0][4].f0) && (0x0C58L <= (g_20.f0.f1 > (((9UL == ((g_90.f0 || (((short) (((unsigned short) l_18[1][0][4].f0) >> ((unsigned short) g_20.f2.f0))) >> ((short) g_20.f5))) != l_55[0])) > 0x0A685D56L) <= l_103)));
    }

  }
  else
  {
    volatile int **l_105 = &g_56[3][0];
    *l_105 = g_56[3][0];
  }

  return g_106[3];
}

static struct S4 *func_2(struct S5 p_3, unsigned p_4, int p_5)
{
  unsigned l_22 = 1UL;
  struct S4 *l_23 = &g_17;
  int l_24 = 0x7EB839B4L;
  struct S4 **l_26 = &l_23;
  struct S4 ***l_25 = &l_26;
  struct S4 *l_27 = &g_17;
  l_22 = 0xFB512259L;
  l_24 = l_23 != l_23;
  *l_25 = &l_23;
  return l_27;
}

static unsigned short func_10(int p_11, int p_12, struct S4 *p_13, unsigned p_14, struct S5 p_15)
{
  struct S3 *l_19[5] = {&g_20, &g_20, &g_20, &g_20, &g_20};
  struct S3 **l_21 = &l_19[2];
  int i;
  *l_21 = l_19[1];
  return g_17.f4;
}

int main(void)
{
  int i;
  int j;
  int print_hash_value = 0;
  platform_main_begin();
  func_1();
  csmith_sink_ = g_6.f0;
  csmith_sink_ = g_17.f0;
  csmith_sink_ = g_17.f1.f0;
  csmith_sink_ = g_17.f1.f1;
  csmith_sink_ = g_17.f1.f2;
  csmith_sink_ = g_17.f1.f3;
  csmith_sink_ = g_17.f1.f4;
  csmith_sink_ = g_17.f1.f5;
  csmith_sink_ = g_17.f1.f6;
  {
    ERROR:
    __VERIFIER_error();

    csmith_sink_ = g_17.f2;
  }
  csmith_sink_ = g_17.f3;
  csmith_sink_ = g_17.f4;
  csmith_sink_ = g_17.f5.f0;
  csmith_sink_ = g_17.f5.f1;
  csmith_sink_ = g_17.f5.f2;
  csmith_sink_ = g_17.f6.f0;
  csmith_sink_ = g_17.f6.f1;
  csmith_sink_ = g_17.f6.f2;
  csmith_sink_ = g_17.f6.f3;
  csmith_sink_ = g_17.f6.f4;
  csmith_sink_ = g_17.f6.f5;
  csmith_sink_ = g_17.f6.f6;
  csmith_sink_ = g_17.f7.f0;
  csmith_sink_ = g_17.f7.f1;
  csmith_sink_ = g_17.f7.f2.f0;
  csmith_sink_ = g_17.f7.f2.f1;
  csmith_sink_ = g_17.f7.f2.f2;
  csmith_sink_ = g_17.f7.f3;
  csmith_sink_ = g_20.f0.f0;
  csmith_sink_ = g_20.f0.f1;
  csmith_sink_ = g_20.f0.f2;
  csmith_sink_ = g_20.f0.f3;
  csmith_sink_ = g_20.f0.f4;
  csmith_sink_ = g_20.f0.f5;
  csmith_sink_ = g_20.f0.f6;
  csmith_sink_ = g_20.f1;
  csmith_sink_ = g_20.f2.f0;
  csmith_sink_ = g_20.f2.f1;
  csmith_sink_ = g_20.f2.f2.f0;
  csmith_sink_ = g_20.f2.f2.f1;
  csmith_sink_ = g_20.f2.f2.f2;
  csmith_sink_ = g_20.f2.f3;
  csmith_sink_ = g_20.f3;
  csmith_sink_ = g_20.f4;
  csmith_sink_ = g_20.f5;
  csmith_sink_ = g_90.f0;
  csmith_sink_ = g_90.f1.f0;
  csmith_sink_ = g_90.f1.f1;
  csmith_sink_ = g_90.f1.f2;
  csmith_sink_ = g_90.f1.f3;
  csmith_sink_ = g_90.f1.f4;
  csmith_sink_ = g_90.f1.f5;
  csmith_sink_ = g_90.f1.f6;
  csmith_sink_ = g_90.f2;
  csmith_sink_ = g_90.f3;
  csmith_sink_ = g_90.f4;
  csmith_sink_ = g_90.f5.f0;
  csmith_sink_ = g_90.f5.f1;
  csmith_sink_ = g_90.f5.f2;
  csmith_sink_ = g_90.f6.f0;
  csmith_sink_ = g_90.f6.f1;
  csmith_sink_ = g_90.f6.f2;
  csmith_sink_ = g_90.f6.f3;
  csmith_sink_ = g_90.f6.f4;
  csmith_sink_ = g_90.f6.f5;
  csmith_sink_ = g_90.f6.f6;
  csmith_sink_ = g_90.f7.f0;
  csmith_sink_ = g_90.f7.f1;
  csmith_sink_ = g_90.f7.f2.f0;
  csmith_sink_ = g_90.f7.f2.f1;
  csmith_sink_ = g_90.f7.f2.f2;
  csmith_sink_ = g_90.f7.f3;
  for (i = 0; i < 6; i = i + 1)
  {
  }

  platform_main_end(0, 0);
  return 0;
}

