/* 1000:7285 */

undefined1 FUN_1000_7285(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  char in_DL;
  char in_DH;
  int unaff_SI;
  undefined2 unaff_DS;
  
  cVar2 = (char)*(undefined2 *)(unaff_SI + 2);
  if (cVar2 == in_DL) {
    bVar3 = (char)((uint)*(undefined2 *)(unaff_SI + 2) >> 8) - in_DH;
    uVar1 = 6;
    if ((bVar3 != 0) && (uVar1 = 4, -1 < (int)((uint)bVar3 << 8))) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 6;
    if (-1 < (char)(cVar2 - in_DL)) {
      uVar1 = 2;
    }
  }
  return uVar1;
}


