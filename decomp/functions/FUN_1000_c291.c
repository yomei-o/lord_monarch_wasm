/* 1000:c291 */

undefined2 __cdecl16near FUN_1000_c291(void)

{
  int iVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  
  iVar1 = (uint)*(byte *)(unaff_SI + 0xb) * 0x80;
  return CONCAT11(3,((byte)((undefined *)&DAT_0000_2400)
                           [iVar1 + (*(uint *)((undefined *)&DAT_0000_247e + iVar1) >> 2)] >>
                     ((byte)*(uint *)((undefined *)&DAT_0000_247e + iVar1) & 3) * '\x02' & 3) *
                    '\x02');
}


