/* 1000:a904 */

undefined2 __cdecl16near FUN_1000_a904(void)

{
  char cVar1;
  undefined2 in_AX;
  byte bVar2;
  byte in_DL;
  int in_BX;
  undefined2 unaff_DS;
  
  bVar2 = 0;
  if ((in_DL != 0) && (bVar2 = 0, 3 < (byte)(((undefined *)&DAT_0000_d27c)[in_BX] - 1))) {
    bVar2 = 1;
  }
  if ((in_DL < 0x2f) && (3 < (byte)(((undefined *)&DAT_0000_d280)[in_BX] - 1))) {
    bVar2 = bVar2 | 2;
  }
  LOCK();
  cVar1 = ((undefined *)&DAT_0000_d27e)[in_BX];
  ((undefined *)&DAT_0000_d27e)[in_BX] = bVar2 + 1;
  UNLOCK();
  if ((byte)(cVar1 - 1U) < 4) {
    ((undefined *)&DAT_0000_d27f)[in_BX] = 100;
  }
  return in_AX;
}


