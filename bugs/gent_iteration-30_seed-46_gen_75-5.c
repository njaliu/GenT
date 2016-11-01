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
static int g_5 = 0xFB023ED1L;
static short g_37 = 4L;
static unsigned short g_45 = 0xBF04L;
static int g_46 = 0x189EFA4EL;
static unsigned g_47 = 0x5F1C2B46L;
static int g_71 = 0x120E7A9FL;
static int func_1(void);
static unsigned short func_6(short p_7, short p_8, int p_9);
static int func_1(void)
{
  unsigned l_4 = 7UL;
  unsigned l_21 = 0xB756FD8CL;
  unsigned short l_69 = 4UL;
  unsigned l_70 = 0xD5384E05L;
  g_47 = ((unsigned short) l_4) >> ((unsigned short) ((g_5 | (g_5 ^ func_6(g_5, ((l_4 ^ ((((((short) (((!((((unsigned short) g_5) >> ((unsigned short) 14)) ^ 65529UL)) && (((int) (g_5 <= (((((((unsigned short) ((((((short) 0xB611L) >> ((short) g_5)) < g_5) && 0xC4F32B7BL) | 0xCDF8ABFFL)) + ((unsigned short) l_4)) < 0L) & l_21) & l_4) <= l_4))) + ((int) g_5))) != g_5)) + ((short) g_5)) <= l_4) ^ g_5) && 0x3BE46552L)) & 4294967294UL) || 8L, l_21))) < l_4));
  g_71 = ((((short) (((unsigned short) g_46) >> ((unsigned short) l_4))) >> ((short) (l_21 == ((((int) ((((int) (((short) (((((unsigned) (l_4 | ((((int) ((((unsigned short) ((0xEB41E225L > (g_47 && (((short) (((unsigned short) ((l_4 || ((((g_46 & (-((unsigned short) (g_5 & g_47)))) >= g_45) | g_46) >= 5UL)) == 0xCA02B236L)) % ((unsigned short) l_4))) >> ((short) l_21)))) >= g_5)) >> ((unsigned short) 5)) < g_46)) - ((int) 0UL)) || g_37))) - ((unsigned) l_69)) < l_70) || g_37)) % ((short) g_5))) % ((int) l_70)) >= 0x3DE1L)) - ((int) l_21)) != g_37)))) && l_4) | g_37;
  return l_4;
}

static unsigned short func_6(short p_7, short p_8, int p_9)
{
  unsigned short l_32 = 0x44F3L;
  int l_44 = -1L;
  if (((int) (((int) ((((short) (((short) (((((short) p_9) << ((short) ((l_32 <= ((-1L) >= (((unsigned short) (((short) ((g_37 < ((l_32 | (g_37 | ((((((short) (((int) p_9) - ((int) (-1L)))) >> ((short) (((unsigned) l_32) + ((unsigned) 0x42C5ACC8L)))) ^ g_37) || p_8) < 0xDDA7L))) <= g_37)) && l_32)) + ((short) 0x9BDDL))) % ((unsigned short) g_5)))) < l_32))) && p_7) < g_37)) << ((short) 1))) + ((short) g_37)) && l_32)) % ((int) 4294967295UL))) + ((int) p_8))
  {
    l_44 = g_37;
    return p_8;
  }
  else
  {
    {
      ERROR:
      __VERIFIER_error();

      g_45 = l_44 & 4294967295UL;
    }
    g_46 = 0x3C3A871DL;
  }

  l_44 = l_32;
  return p_7;
}

int main(void)
{
  int print_hash_value = 0;
  platform_main_begin();
  func_1();
  csmith_sink_ = g_5;
  csmith_sink_ = g_37;
  csmith_sink_ = g_45;
  csmith_sink_ = g_46;
  csmith_sink_ = g_47;
  csmith_sink_ = g_71;
  platform_main_end(0, 0);
  return 0;
}

