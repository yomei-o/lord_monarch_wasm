/* 1000:adeb */

undefined4 __cdecl16near FUN_1000_adeb(void)

{
  char cVar1;
  undefined2 in_AX;
  undefined2 uVar2;
  char cVar3;
  int unaff_DI;
  undefined2 unaff_DS;
  
  uVar2 = 0;
  cVar1 = (char)in_AX;
  if (((undefined *)&DAT_0000_d2e0)[unaff_DI] == '\0') {
    uVar2 = 1;
  }
  else if (((undefined *)&DAT_0000_d2e0)[unaff_DI] == cVar1) {
    uVar2 = 0x100;
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d2dc)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d2dc)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d220)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d220)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d21c)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d21c)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d280)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d280)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d27c)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d27c)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d2de)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d2de)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  cVar3 = (char)((uint)uVar2 >> 8);
  if (((undefined *)&DAT_0000_d21e)[unaff_DI] == '\0') {
    uVar2 = CONCAT11(cVar3,(char)uVar2 + '\x01');
  }
  else if (((undefined *)&DAT_0000_d21e)[unaff_DI] == cVar1) {
    uVar2 = CONCAT11(cVar3 + '\x01',(char)uVar2);
  }
  return CONCAT22(uVar2,in_AX);
}


