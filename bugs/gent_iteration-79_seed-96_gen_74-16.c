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
static unsigned short g_2 = 0xA631L;
static short g_34 = 0xF205L;
static int g_41 = 0L;
static unsigned g_47 = 0x5EFB48CAL;
static int g_73 = -8L;
static int func_1(void);
static int func_5(unsigned p_6, unsigned p_7, int p_8, unsigned p_9, unsigned p_10);
static int func_1(void)
{
  unsigned l_86 = 4294967289UL;
  unsigned l_102 = 0x879CFBC8L;
  unsigned l_118 = 5UL;
  int l_122 = 0x46617F50L;
  if (g_2)
  {
    unsigned short l_14 = 0xC341L;
    int l_82 = 6L;
    for (g_2 = 15; g_2 >= 14; g_2 -= 1)
    {
      short l_11 = 0x21DEL;
      l_82 = func_5(l_11, g_2, g_2, l_11, (4294967287UL && (((int) (l_14 != ((((((0L > ((g_2 >= g_2) || g_2)) < 0x39E071A0L) < 1UL) < l_11) ^ l_11) < 2L))) + ((int) l_11))) == 0L);
    }

  }
  else
  {
    int l_83 = -1L;
    l_83 = l_83 ^ (((((((((((short) g_47) % ((short) l_86)) & (((unsigned short) (0x587BB5B2L & (g_47 && (((int) ((((unsigned) g_34) + ((unsigned) (0x29F9L | 1L))) || 3L)) - ((int) l_86))))) >> ((unsigned short) g_41))) ^ 0x794FL) && g_34) > 4294967295UL) > (-1L)) != l_86) != g_73) < l_86);
  }

  if (0xAC2835E5L >= g_41)
  {
    short l_99 = -1L;
    short l_117 = 0x2A55L;
    g_41 = ((unsigned short) ((((unsigned short) ((((short) (l_99 & ((0x58462BD5L >= ((((unsigned short) g_73) + ((unsigned short) g_47)) < g_34)) <= l_102))) % ((short) ((((int) ((((((((short) ((-1L) <= (((short) (((short) ((((((((unsigned short) ((((0x65FAL != ((((((short) ((((((((unsigned short) l_86) << ((unsigned short) g_73)) != l_102) != l_99) & l_102) < l_99) || g_73)) - ((short) l_86)) | 0x4AA9L) | l_99) || l_99)) & 1L) | g_73) & g_2)) << ((unsigned short) 1)) <= 0x0F311A8DL) | 0x2B75L) & l_86) & 1L) & l_86)) - ((short) 0xDD2FL))) << ((short) 13)))) % ((short) g_73)) < l_102) ^ g_2) <= 1L) | g_34) || g_41)) + ((int) 0L)) & g_73))) & l_117)) % ((unsigned short) g_2)) < g_73)) << ((unsigned short) l_118);
  }
  else
  {
    int l_121 = 0x813F23DCL;
    l_122 = ((unsigned short) (g_34 || (0xBDD5L & l_121))) >> ((unsigned short) 4);
    {
      ERROR:
      __VERIFIER_error();

      return g_2;
    }
  }

  return g_41;
}

static int func_5(unsigned p_6, unsigned p_7, int p_8, unsigned p_9, unsigned p_10)
{
  short l_17 = 0x040CL;
  int l_75 = 0x65C99C23L;
  if (((unsigned short) l_17) >> ((unsigned short) 15))
  {
    unsigned short l_40 = 0x8A41L;
    for (l_17 = 3; l_17 < 0; l_17 -= 6)
    {
      for (p_6 = -18; p_6 < 45; p_6 += 5)
      {
        unsigned l_35 = 0x5A1EC8F9L;
        for (p_10 = 18; p_10 != 57; p_10 += 8)
        {
          unsigned l_24 = 0UL;
          p_8 = l_24;
        }

        g_41 = ((((((unsigned short) ((((p_8 && g_2) ^ (((short) l_17) << ((short) (((((unsigned short) (-((unsigned) 4294967295UL))) << ((unsigned short) 2)) >= (((unsigned short) g_34) + ((unsigned short) (l_35 && (((((int) (-1L)) - ((int) g_2)) > (((((unsigned) (((l_40 < g_34) < l_35) != p_7)) - ((unsigned) g_2)) == g_34) & p_7)) != p_9))))) > l_35)))) < g_34) > p_9)) >> ((unsigned short) 6)) && g_2) >= g_34) | g_2) && g_2;
      }

    }

    for (g_41 = 19; g_41 == 5; g_41 -= 1)
    {
      unsigned l_44 = 0xA8E7E64BL;
      int l_70 = -10L;
      if (l_44)
      {
        g_47 = (((unsigned short) (p_10 | 65535UL)) >> ((unsigned short) 12)) & p_8;
        if (p_8)
          continue;

      }
      else
      {
        if (((short) ((0xC39FL || (((short) ((((((short) ((((unsigned short) ((((unsigned short) (l_40 == (((short) (-7L)) >> ((short) 1)))) >> ((unsigned short) 9)) | ((((((~(((unsigned) 1UL) % ((unsigned) 0xFB8AAA84L))) <= l_40) <= ((((short) ((0xEF15L > (l_40 != (((unsigned short) p_10) - ((unsigned short) 0x93CDL)))) ^ l_44)) >> ((short) 6)) | g_2)) || g_34) > 4294967295UL) > g_2))) >> ((unsigned short) 6)) || p_8)) >> ((short) 15)) && g_2) || 0x95AE89E6L) | l_17)) - ((short) 5UL))) <= 0L)) << ((short) 2))
        {
          l_70 = ((short) (!g_2)) >> ((short) 15);
        }
        else
        {
          unsigned short l_74 = 5UL;
          for (l_44 = 27; l_44 < 9; l_44 -= 1)
          {
            g_73 = p_9;
            l_75 = l_74;
          }

        }

      }

      return g_73;
    }

  }
  else
  {
    unsigned l_79 = 4294967295UL;
    for (p_8 = 0; p_8 == (-16); p_8 -= 1)
    {
      short l_78 = 0x559FL;
      l_79 = g_2 & l_78;
      if (g_73)
        continue;

    }

  }

  p_8 = ((unsigned short) g_47) >> ((unsigned short) 3);
  return l_75;
}

int main(void)
{
  int print_hash_value = 0;
  platform_main_begin();
  func_1();
  csmith_sink_ = g_2;
  csmith_sink_ = g_34;
  csmith_sink_ = g_41;
  csmith_sink_ = g_47;
  csmith_sink_ = g_73;
  platform_main_end(0, 0);
  return 0;
}

