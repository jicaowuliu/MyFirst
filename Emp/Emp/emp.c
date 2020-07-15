#include <stdio.h>
#include <string.h>

void mainmenu();
int iniemp();
void writedata();
int calchar(char a[]);
void findallemp();
void empmenu();
void countnum();
void addemp();
void delemp();
void updateemp1();
void updateemp2(int i);
void updateAll(int i);
void updateName(int i);
void updateMail(int i);
void updateTel(int i);
void updateId(int i);
void updateDate(int i);
void sortbyname();
void sortbydate();
void findempbynameorid();
void findempbydate();
//员工结构体
struct emp {
	int num;
	char name[20];
	char mail[25];
	char id[20];
	char tel[20];
	double date;
};
//选项
char choice[20];
//员工数组
struct emp emplist[100];
//员工数
int empnum;
//数据库更新
void writedata() {
	FILE *fp;
	if ((fp = fopen("emp.txt", "w")) == NULL) {
		printf("cannot open file strike any key exit!");
		getch();
		exit();
	}
	for (int i = 0; i < empnum; i++) {
		if (emplist[i].date == 0) {
			continue;
		}
		fputs("name=", fp);
		fputs(emplist[i].name, fp);
		fputs("\n", fp);
		fputs("mail=", fp);
		fputs(emplist[i].mail, fp);
		fputs("\n", fp);
		fputs("id=", fp);
		fputs(emplist[i].id, fp);
		fputs("\n", fp);
		fputs("tel=", fp);
		fputs(emplist[i].tel, fp);
		fputs("\n", fp);
		fputs("date=", fp);
		fprintf(fp, "%.2f", emplist[i].date);
		fputs("\n", fp);
		fputs("\n", fp);
	}
	printf("数据更新成功");
	fclose(fp);
}
//取名字首字母
int calchar(char a[]) {
	double charnum = 0;
	int k = 0;
	while (a[k] == '\0') {
		k++;
	}
	charnum = (int)a[k];
	return charnum;
}
//计算员工数
void countnum() {
	int i = 0;
	while (emplist[i].num == i) {
		i++;
	}
	empnum = i;
}
//添加员工
void addemp() {
	char ch[5], name[20], mail[25], id[20], tel[20];
	double date;
	printf("请输入员工姓名\n");
	scanf("%s", name);
	printf("请输入员工邮箱\n");
	scanf("%s", mail);
	printf("请输入员工编号\n");
	scanf("%s", id);
	printf("请输入员工电话\n");
	scanf("%s", tel);
	printf("请输入入社日期（例如2005.10）\n");
	scanf("%lf", &date);
	printf("确认添加该员工（Y/N）\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		for (int h = 0; h < empnum; h++) {
			if (strcmp(emplist[h].id, id) == 0) {
				printf("添加失败，该员工编号已存在！\n");
				mainmenu();
				return;
			}
		}
		if (date == 0) {
			printf("入社日期不能为0\n");
			mainmenu();
			return;
		}
		int i = empnum;
		emplist[i].num = i;
		emplist[i].date = date;
		int j = 0;
		while (name[j] != '\0') {
			emplist[i].name[j] = name[j];
			j++;
		}
		j = 0;
		while (mail[j] != '\0') {
			emplist[i].mail[j] = mail[j];
			j++;
		}
		j = 0;
		while (id[j] != '\0') {
			emplist[i].id[j] = id[j];
			j++;
		}
		j = 0;
		while (tel[j] != '\0') {
			emplist[i].tel[j] = tel[j];
			j++;
		}
		
		printf("添加成功！\n");
		empnum++;
	}
	printf("\n");
	mainmenu();
}

//修改员工信息
void updateemp1() {
	char id[20];
	int count = 0;
	int index;
	printf("请输入你要修改的员工的编号或姓名！(当符合仅有一人时可以修改)\n");
	scanf("%s", id);
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, id) || strstr(emplist[i].id, id)) {
			printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");
			break;
		}
	}
	
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, id) || strstr(emplist[i].id, id)) {
			printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
			printf("\n");
			count++;
			index = i;
		}
	}
	if (count > 1) {
		updateemp1();
	}
	else if(count == 0){
		printf("本公司没有该员工！\n");
		mainmenu();
		return;
	}
	else if (count == 1) {
		updateemp2(index);
		return;
	}
	
}
void updateemp2(int i) {
	printf("************************************\n");
	printf("*           1.修改所有信息         *\n");
	printf("*           2.修改姓名             *\n");
	printf("*           3.修改编号             *\n");
	printf("*           4.修改邮箱             *\n");
	printf("*           5.修改电话             *\n");
	printf("*           6.修改入社日期         *\n");
	printf("*           7.返回上级菜单         *\n");
	printf("************************************\n");
	printf("请选择\n");
	scanf("%s", choice);
	if (strcmp(choice, "1") == 0) {
		updateAll(i);
	}
	else if (strcmp(choice, "2") == 0) {
		updateName(i);
	}
	else if (strcmp(choice, "3") == 0) {
		updateId(i);
	}
	else if (strcmp(choice, "4") == 0) {
		updateMail(i);
	}
	else if (strcmp(choice, "5") == 0) {
		updateTel(i);
	}
	else if (strcmp(choice, "6") == 0) {
		updateDate(i);
	}
	else if (strcmp(choice, "7") == 0) {
		mainmenu();
	}
	else {
		printf("请输入正确的选项\n");
		findallemp();
	}
}

void updateAll(int i) {
	char ch[5], name[20], mail[25], id[20], tel[20];
	double date;
	printf("请输入更新后员工姓名\n");
	scanf("%s", name);
	printf("请输入更新后员工邮箱\n");
	scanf("%s", mail);
	printf("请输入更新后员工编号\n");
	scanf("%s", id);
	printf("请输入更新后员工电话\n");
	scanf("%s", tel);
	printf("请输入更新后入社日期\n");
	scanf("%lf", &date);
	printf("确认更新该员工信息（Y/N）\n");
	scanf("%s", ch);
	if(strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		if (sizeof(tel) != 11) {
			printf("更新失败，手机号错误！\n");
			mainmenu();
			return;
		}
		for (int h = 0; h < empnum; h++) {
			if (strcmp(emplist[h].id, id) == 0) {
				printf("更新失败，该员工编号已存在！\n");
				mainmenu();
				return;
			}
		}
		emplist[i].num = i;
		emplist[i].date = date;
		int j = 0;
		while (name[j] != '\0') {
			emplist[i].name[j] = name[j];
			j++;
		}
		j = 0;
		while (mail[j] != '\0') {
			emplist[i].mail[j] = mail[j];
			j++;
		}
		j = 0;
		while (id[j] != '\0') {
			emplist[i].id[j] = id[j];
			j++;
		}
		j = 0;
		while (tel[j] != '\0') {
			emplist[i].tel[j] = tel[j];
			j++;
		}
		printf("更新成功！\n");
		mainmenu();
	}
}

void updateName(int i) {
	char name[20], ch[5];
	printf("请输入更新后员工姓名\n");
	scanf("%s", name);
	printf("确认更新该员工信息（Y/N）\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		int j = 0;
		while (name[j] != '\0') {
			emplist[i].name[j] = name[j];
			j++;
		}
		printf("更新成功！\n");
	}

	updateemp2(i);
}

void updateId(int i) {
	char id[20], ch[5];
	printf("请输入更新后员工编号\n");
	scanf("%s", id);
	printf("确认更新该员工信息（Y/N）\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		int j = 0;
		while (id[j] != '\0') {
			emplist[i].id[j] = id[j];
			j++;
		}
		printf("更新成功！\n");
	}

	updateemp2(i);
}

void updateMail(int i) {
	char mail[20], ch[5];
	printf("请输入更新后员工姓名\n");
	scanf("%s", mail);
	printf("确认更新该员工信息（Y/N）\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		int j = 0;
		while (mail[j] != '\0') {
			emplist[i].mail[j] = mail[j];
			j++;
		}
		printf("更新成功！\n");
	}

	updateemp2(i);
}

void updateTel(int i) {
	char tel[20], ch[5];
	printf("请输入更新后员工电话\n");
	scanf("%s", tel);
	printf("确认更新该员工信息（Y/N）\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		if (sizeof(tel) != 11) {
			printf("更新失败，手机号错误！\n");
			mainmenu();
			return;
		}
		int j = 0;
		while (tel[j] != '\0') {
			emplist[i].tel[j] = tel[j];
			j++;
		}
		printf("更新成功！\n");
	}

	updateemp2(i);
}

void updateDate(int i) {
	double date, ch[5];
	printf("请输入更新后入社日期\n");
	scanf("%lf", &date);
	printf("确认更新该员工信息（Y/N）\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		if (date > 0) {
			emplist[i].date = date;
			printf("更新成功！\n");
		}
		else {
			printf("入社日期不能为空，请重新输入\n");
			updateDate(i);
			return;
		}
	}

	updateemp2(i);
}

//删除员工
void delemp() {
	char del[20],ch[5];
	printf("请输入要删除的员工编号或姓名\n");
	scanf("%s", del);
	printf("\n");
	for (int i = 0; i < empnum; i++) {
		if (strcmp(emplist[i].id, del) == 0 || strcmp(emplist[i].name, del) == 0) {
			printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");
			printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
			printf("\n");
			printf("确认删除该员工（Y/N）\n");
			scanf("%s", ch);
			if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
				emplist[i].num = '\0';
				int j = 0;
				while (emplist[i].name[j] != '\0') {
					emplist[i].name[j] = '\0';
					j++;
				}
				j = 0;
				while (emplist[i].mail[j] != '\0') {
					emplist[i].mail[j] = '\0';
					j++;
				}
				j = 0;
				while (emplist[i].tel[j] != '\0') {
					emplist[i].tel[j] = '\0';
					j++;
				}
				j = 0;
				while (emplist[i].id[j] != '\0') {
					emplist[i].id[j] = '\0';
					j++;
				}
				emplist[i].date = '\0';
				printf("删除成功！\n");
				mainmenu();
				return;
			}
			else {
				mainmenu();
				return;
			}
		}
	}
	printf("本公司没有该员工！\n");
	mainmenu();
}

//按名字排序
void sortbyname() {
	
	//下标数组
	int sort[100];
	//姓名数组
	int sortname[100];
	
	int x = 0, flag = 0, g = 0, tmp = 0;
	printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");
	for (int i = 0; i < empnum; i++) {
		if (emplist[i].date == 0) {
			continue;
		}
		sortname[x] = calchar(emplist[i].name);
		x++;
	}
	for (int i = 0; i < x - 1; i++) {
		for (int k = 0; k < x - i -1; k++) {
			if (sortname[k] > sortname[k+1]) {
				tmp = sortname[k];
				sortname[k] = sortname[k+1];
				sortname[k+1] = tmp;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		for (int k = 0; k < empnum; k++) {
			if (calchar(emplist[k].name) == sortname[i]) {
				for (int h = 0; h < g; h++) {
					if (sort[h] == k) {
						flag = 1;
					}
				}
				if (flag == 0) {
					sort[g] = k;
					g++;
					printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[k].name, emplist[k].mail, emplist[k].id, emplist[k].tel, emplist[k].date);
					printf("\n");
				}

				flag = 0;
			}

		}
	}
	empmenu();
}

//按入社日期排序
void sortbydate() {
	//入社日期数组
	double sortdate[100];
	//下标数组
	int sort[100];
	int j = 0, flag = 0, g = 0;
	double tmp = 0;
	printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");
	for (int i = 0; i < empnum; i++) {
		if (emplist[i].date == 0) {
			continue;
		}
		sortdate[j] = emplist[i].date;
		j++;
	}
	for (int i = 0; i < j - 1; i++) {
		for (int k = 0; k < j - i - 1; k++) {
			if (sortdate[k] > sortdate[k+1]) {
				tmp = sortdate[k];
				sortdate[k] = sortdate[k+1];
				sortdate[k+1] = tmp;
			}
		}
	}
	for (int i = 0; i < j; i++) {
		for (int k = 0; k < empnum; k++) {
			if (emplist[k].date == sortdate[i]) {
				for (int h = 0; h < g; h++) {
					if (sort[h] == k) {
						flag = 1;
					}
				}
				if (flag == 0) {
					sort[g] = k;
					g++;
					printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[k].name, emplist[k].mail, emplist[k].id, emplist[k].tel, emplist[k].date);
					printf("\n");
				}

				flag = 0;
			}

		}
	}
	empmenu();
}

//按名字查找员工
void findempbynameorid() {
	char nameid[20];
	int flag = 0;
	printf("请输入查找员工的姓名或编号\n");
	scanf("%s", nameid);
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, nameid) || strstr(emplist[i].id, nameid)) {
			flag = 1;

		}
	}
	if (flag == 1) {
		printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");
	}
	else {
		printf("本公司没有该员工！\n");
	}
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, nameid) || strstr(emplist[i].id, nameid)) {
			printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
			printf("\n");
		}
	}
	empmenu();
}

//按入社日期查找员工
void findempbydate() {
	int flag = 0;
	double start = 0, end = 0;
	printf("请输入起始年月(例如：2012.05,或者0)\n");
	scanf("%lf", &start);
	printf("请输入结束年月(例如：2012.11,或者0)\n");
	scanf("%lf", &end);
	
	for (int i = 0; i < empnum; i++) {
		if (emplist[i].date == 0) {
			continue;
		}
		if (start == 0 && end != 0) {
			if (emplist[i].date <= end) {
				flag = 1;
			}
		}
		else if (end == 0 && start != 0) {
			if (emplist[i].date >= start) {
				flag = 1;
			}
		}
		else if (start == 0 && end == 0) {
			flag = 1;
		}
		else {
			if (emplist[i].date >= start && emplist[i].date <= end) {
				flag = 1;
			}
		}

	}
	
	if (flag == 1) {
		printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");
	}
	else {
		printf("该时间段没有员工入职！\n");
	}
	for (int i = 0; i < empnum; i++) {
		if (emplist[i].date == 0) {
			continue;
		}
		if (start == 0 && end != 0) {
			if (emplist[i].date <= end) {
				printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
				printf("\n");
			}
		}
		else if (end == 0 && start != 0) {
			if (emplist[i].date >= start) {
				printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
				printf("\n");
			}
		}
		else if (start == 0 && end == 0) {
			printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
			printf("\n");
		}
		else {
			if (emplist[i].date >= start && emplist[i].date <= end) {
				printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
				printf("\n");
			}
		}
	}
	empmenu();
}

//显示所有员工信息
void findallemp() {
	int i = 0;
	printf("员工列表\n");
	printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t入社日期\n");

	for (int i = 0; i < empnum; i++) {
		if (emplist[i].date == 0) {
			continue;
		}
		printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
		printf("\n");

	}
	empmenu();
}

void empmenu() {
	printf("\n");
	printf("*************************************\n");
	printf("*          1.返回主菜单             *\n");
	printf("*          2.按名字排序             *\n");
	printf("*          3.按入社日期排序         *\n");
	printf("*          4.按入社日期查找员工     *\n");
	printf("*          5.按名字编号查找员工     *\n");
	printf("*          6.退出系统               *\n");
	printf("*************************************\n");
	printf("请选择\n");
	/*scanf("%d",&choice);
	switch (choice)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		sortbyname();
		break;
	case 3:
		sortbydate();
		break;
	case 4:
		findempbydate();
		break;
	case 5:
		findempbyname();
		break;
	default:
		printf("请输入正确的选项\n");
		findallemp();
		break;
	}*/
	scanf("%s", choice);
	if (strcmp(choice, "1") == 0) {
		mainmenu();
	}
	else if (strcmp(choice, "2") == 0) {
		sortbyname();
	}
	else if (strcmp(choice, "3") == 0) {
		sortbydate();
	}
	else if (strcmp(choice, "4") == 0) {
		findempbydate();
	}
	else if (strcmp(choice, "5") == 0) {
		findempbynameorid();
	}
	else if (strcmp(choice, "6") == 0) {
		writedata();
		exit();
	}
	else {
		printf("请输入正确的选项\n");
		findallemp();
	}
}

//读取数据库，初始化员工数组
int iniemp() {
	FILE *fp = fopen("emp.txt", "r");
	if (fp == NULL) {
		printf("error\n");
	}
	char st, str[30], ch[30];
	int i = 0, j = 0, k = 0, flag = 0, tmpdate = 0, tmp = 0;
	while (EOF != (st = fgetc(fp))) {
		if (st == '\n') {
			flag = 0;
			int divisor = 1;
			ch[j] = '\0';
			str[k] = '\0';

			if (strstr(str, "name")) {
				for (int t = 0; t <= j; t++) {
					emplist[i].name[t] = ch[t];
				}
				//printf("%s",emplist[i].name);
				emplist[i].num = i;
			}
			if (strstr(str, "mail")) {
				for (int t = 0; t <= j; t++) {
					emplist[i].mail[t] = ch[t];
				}
			}
			if (strstr(str, "id")) {
				for (int t = 0; t <= j; t++) {
					emplist[i].id[t] = ch[t];
				}
			}
			if (strstr(str, "tel")) {
				for (int t = 0; t <= j; t++) {
					emplist[i].tel[t] = ch[t];
				}
			}
			if (strstr(str, "date")) {
				for (int t = 0; t <= j; t++) {
					if (ch[t] == '\0') {
						break;
					}
					if (ch[t] == '.') {
						flag = 1;
						continue;
					}
					if (flag == 1) {
						divisor = divisor * 10;
					}

					tmp = (int)ch[t] - 48;
					tmpdate = tmpdate * 10 + tmp;
				}
				emplist[i].date = (double)tmpdate / divisor;
				tmpdate = 0;
				i++;
			}
			for (int h = 0; h < j; h++) {
				ch[h] = '\0';
			}
			for (int h = 0; h < k; h++) {
				str[h] = '\0';
			}
			j = 0;
			k = 0;
		}
		else {
			if (st == '=') {
				flag = 1;
				continue;
			}
			if (flag == 1) {
				ch[j] = st;
				j++;
			}
			else
			{
				str[k] = st;
				k++;
			}
		}

	}
	fclose(fp);
	return i;
}

//主菜单
void mainmenu() {
	printf("************************************\n");
	printf("*         职员信息管理系统         *\n");
	printf("*           1.添加职员             *\n");
	printf("*           2.删除职员             *\n");
	printf("*           3.修改职员             *\n");
	printf("*           4.查看职员             *\n");
	printf("*           5.退出系统             *\n");
	printf("************************************\n");
	printf("请选择\n");
	scanf("%s", choice);
	if (strcmp(choice, "1") == 0) {
		addemp();
	}
	else if (strcmp(choice, "2") == 0) {
		delemp();
	}
	else if (strcmp(choice, "3") == 0) {
		updateemp1();
	}
	else if (strcmp(choice, "4") == 0) {
		findallemp();
	}
	else if (strcmp(choice, "5") == 0) {
		writedata();
		exit();
	}
	else {
		printf("请输入正确的选项\n");
		mainmenu();
	}
}
int main(void) {

	iniemp();
	countnum();
	mainmenu();

	return 0;
}