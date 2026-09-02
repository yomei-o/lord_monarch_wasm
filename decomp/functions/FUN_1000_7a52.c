/* 1000:7a52 */

uint __cdecl16near FUN_1000_7a52(void)

{
  uint in_AX;
  int iVar1;
  undefined1 *unaff_DI;
  
  iVar1 = (in_AX & 0xff) + 0x2500;
  FUN_1000_724a();
  *unaff_DI = *(undefined1 *)0x0;
  unaff_DI[0x50] = *(undefined1 *)0x1;
  unaff_DI[0xa0] = *(undefined1 *)0x2;
  unaff_DI[0xf0] = *(undefined1 *)0x3;
  unaff_DI[0x140] = *(undefined1 *)0x4;
  unaff_DI[400] = *(undefined1 *)0x5;
  unaff_DI[0x1e0] = *(undefined1 *)0x6;
  unaff_DI[0x230] = *(undefined1 *)0x7;
  unaff_DI[0x280] = *(undefined1 *)0x8;
  unaff_DI[0x2d0] = *(undefined1 *)0x9;
  unaff_DI[800] = *(undefined1 *)0xa;
  unaff_DI[0x370] = *(undefined1 *)0xb;
  unaff_DI[0x3c0] = *(undefined1 *)0xc;
  unaff_DI[0x410] = *(undefined1 *)0xd;
  unaff_DI[0x460] = *(undefined1 *)0xe;
  unaff_DI[0x4b0] = *(undefined1 *)0xf;
  out(0x7c,0);
  return in_AX;
}


