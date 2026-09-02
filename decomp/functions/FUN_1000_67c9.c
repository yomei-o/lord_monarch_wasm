/* 1000:67c9 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Stack frame is not setup normally: Input value of stackpointer is not used */

void FUN_1000_67c9(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 in_AX;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined2 in_CX;
  uint uVar7;
  int in_DX;
  char cVar9;
  undefined2 uVar8;
  int in_BX;
  uint *unaff_BP;
  int unaff_DI;
  uint uVar10;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  uVar3 = CONCAT11((char)in_CX,(char)in_AX);
  uVar7 = CONCAT11((char)((uint)in_CX >> 8),(char)((uint)in_AX >> 8));
  uVar10 = uVar3 + 0x1552;
  uVar4 = uVar10 + CARRY2(uVar7,uVar7);
  cVar2 = *(char *)(*unaff_BP + unaff_DI + -8);
  bVar6 = (byte)(uVar7 * 2);
  *unaff_BP = uVar4;
  uVar10 = unaff_DI +
           CONCAT11((char)(uVar7 * 2 >> 8) + cVar2 +
                    (0xeaad < uVar3 || CARRY2(uVar10,(uint)CARRY2(uVar7,uVar7))),bVar6);
  pcVar1 = (char *)(uVar10 + 0xebf);
  *pcVar1 = (*pcVar1 - (char)uVar4) - (0xfd73 < uVar10);
  *(int *)0xccfe = *(int *)0xccfe + 1;
  uVar4 = uVar4 & *(uint *)0x4eaa;
  out(in_DX,uVar4);
  *(undefined1 *)0x1247 = 0;
  *(undefined2 *)0x614 = *(undefined2 *)0x4eaa;
  *(undefined2 *)(in_DX + 0x616) = *(undefined2 *)0x4eac;
  unaff_BP[-1] = unaff_ES;
  *(byte *)0x4eae = *(byte *)0x4eae ^ bVar6;
  cVar9 = (char)((uint)in_DX >> 8);
  cVar2 = (char)uVar4 - cVar9;
  uVar5 = (undefined1)(uVar4 >> 8);
  uVar8 = CONCAT11(cVar9,(char)in_DX - *(char *)(in_BX + 0x4eae));
  out(uVar8,CONCAT11(uVar5,cVar2));
  out(uVar8,CONCAT11(uVar5,cVar2 + 's'));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


