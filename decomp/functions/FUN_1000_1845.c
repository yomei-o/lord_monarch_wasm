/* 1000:1845 */

/* WARNING: Instruction at (ram,0x00011860) overlaps instruction at (ram,0x0001185f)
    */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_1000_1845(void)

{
  byte *pbVar1;
  char *pcVar2;
  byte bVar3;
  undefined2 uVar4;
  uint uVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  int in_BX;
  int *piVar11;
  uint uVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  int unaff_BP;
  char *unaff_SI;
  undefined2 unaff_SS;
  int unaff_DS;
  undefined1 uVar16;
  char cVar17;
  undefined4 uVar18;
  int in_stack_0000000a;
  int in_stack_00000010;
  int in_stack_00000016;
  
  bVar6 = func_0x00017b9e();
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] & bVar6;
  unaff_SI[in_BX + -0x360] =
       unaff_SI[in_BX + -0x360] + (char)in_BX + (0x55 < *(byte *)(in_BX + -0x7a));
  pcVar2 = unaff_SI;
  *pcVar2 = *pcVar2 + (char)((uint)in_BX >> 8);
  if (*pcVar2 == '\0') {
    *(undefined1 *)0x3bfc = 2;
  }
  while( true ) {
    FUN_1000_6e0c();
    FUN_1000_4b03();
    piVar11 = (int *)0x1900;
    uVar16 = 0xf871 < (uint)*(byte *)0x3c00 * 0x1900;
    FUN_1000_915b();
    func_0x00014c82();
    FUN_1000_6e3f();
    iVar13 = in_stack_0000000a;
    do {
      do {
        in_stack_0000000a = iVar13;
        bVar6 = func_0x00014cda();
        if ((bool)uVar16) {
          return;
        }
        uVar16 = bVar6 < *(byte *)0x3c00;
        iVar13 = in_stack_0000000a;
      } while (bVar6 == *(byte *)0x3c00);
      piVar11 = (int *)*(int *)((int)piVar11 * 2 + 0x12ef);
      uVar16 = 0;
      unaff_DS = in_stack_0000000a;
      iVar13 = unaff_BP;
    } while (*piVar11 != 0);
    uVar8 = piVar11[5];
    uVar12 = piVar11[4];
    uVar18 = func_0x0001a6bc();
    uVar10 = (uint)((ulong)uVar18 >> 0x10);
    uVar12 = (uint)((uint)uVar18 < uVar12);
    uVar5 = uVar8 - uVar10;
    bVar6 = (byte)(uVar5 - uVar12);
    if (uVar8 >= uVar10 && uVar5 >= uVar12) break;
    iVar13 = (uint)*(byte *)0x3bfc * 2;
    uVar4 = *(undefined2 *)(iVar13 + 0x12ad);
    *(undefined2 *)0xc52e = uVar4;
    pbVar1 = (byte *)(unaff_SI + unaff_BP);
    bVar3 = *pbVar1;
    bVar7 = (byte)((uint)uVar4 >> 8);
    *pbVar1 = *pbVar1 - bVar7;
    bVar9 = (byte)(uVar5 - uVar12 >> 8);
    cVar17 = CARRY1(bVar6,bVar9) || CARRY1(bVar6 + bVar9,bVar3 < bVar7);
    out(uVar10,uVar4);
    in_stack_00000010 = 0x18d8;
    func_0x0001782d();
    func_0x00014b05();
    unaff_SI[iVar13] = unaff_SI[iVar13] + bVar9 + cVar17;
    puVar14 = (undefined1 *)(in_stack_00000016 + -2);
    *(undefined2 *)(in_stack_00000016 + -2) = 0x18e6;
    FUN_1000_45db();
    puVar15 = puVar14 + -2;
    *(undefined2 *)(puVar14 + -2) = 0x18e9;
    FUN_1000_6e3b();
    *(undefined2 *)(puVar15 + -2) = 0x18ec;
    func_0x0001c49d();
  }
  pcVar2 = (char *)(unaff_BP + in_stack_00000010 + 0xeb);
  *pcVar2 = *pcVar2 + bVar6 + (uVar8 < uVar10 || uVar5 < uVar12);
  FUN_1000_089f();
  FUN_1000_196f();
  FUN_1000_196f();
  FUN_1000_1982();
  FUN_1000_1982();
  FUN_1000_1982();
  FUN_1000_1982();
  func_0x0001782b();
  FUN_1000_4b03();
  *(undefined1 *)0x3bfc = 0;
  FUN_1000_45c7();
  func_0x00016e27();
  func_0x0001c489();
  return;
}


