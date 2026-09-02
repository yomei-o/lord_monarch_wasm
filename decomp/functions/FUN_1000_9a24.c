/* 1000:9a24 */

undefined1 __cdecl16near FUN_1000_9a24(void)

{
  char in_AL;
  undefined1 uVar1;
  ulong uVar2;
  
  uVar1 = 0;
  if (in_AL != '\0') {
    uVar2 = FUN_1000_9a36();
    uVar1 = (undefined1)((uint)((int)(uVar2 & 0xff00ff) * (int)((uVar2 & 0xff00ff) >> 0x10)) >> 8);
  }
  return uVar1;
}


