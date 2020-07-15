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
//Ա���ṹ��
struct emp {
	int num;
	char name[20];
	char mail[25];
	char id[20];
	char tel[20];
	double date;
};
//ѡ��
char choice[20];
//Ա������
struct emp emplist[100];
//Ա����
int empnum;
//���ݿ����
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
	printf("���ݸ��³ɹ�");
	fclose(fp);
}
//ȡ��������ĸ
int calchar(char a[]) {
	double charnum = 0;
	int k = 0;
	while (a[k] == '\0') {
		k++;
	}
	charnum = (int)a[k];
	return charnum;
}
//����Ա����
void countnum() {
	int i = 0;
	while (emplist[i].num == i) {
		i++;
	}
	empnum = i;
}
//���Ա��
void addemp() {
	char ch[5], name[20], mail[25], id[20], tel[20];
	double date;
	printf("������Ա������\n");
	scanf("%s", name);
	printf("������Ա������\n");
	scanf("%s", mail);
	printf("������Ա�����\n");
	scanf("%s", id);
	printf("������Ա���绰\n");
	scanf("%s", tel);
	printf("�������������ڣ�����2005.10��\n");
	scanf("%lf", &date);
	printf("ȷ����Ӹ�Ա����Y/N��\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		for (int h = 0; h < empnum; h++) {
			if (strcmp(emplist[h].id, id) == 0) {
				printf("���ʧ�ܣ���Ա������Ѵ��ڣ�\n");
				mainmenu();
				return;
			}
		}
		if (date == 0) {
			printf("�������ڲ���Ϊ0\n");
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
		
		printf("��ӳɹ���\n");
		empnum++;
	}
	printf("\n");
	mainmenu();
}

//�޸�Ա����Ϣ
void updateemp1() {
	char id[20];
	int count = 0;
	int index;
	printf("��������Ҫ�޸ĵ�Ա���ı�Ż�������(�����Ͻ���һ��ʱ�����޸�)\n");
	scanf("%s", id);
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, id) || strstr(emplist[i].id, id)) {
			printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");
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
		printf("����˾û�и�Ա����\n");
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
	printf("*           1.�޸�������Ϣ         *\n");
	printf("*           2.�޸�����             *\n");
	printf("*           3.�޸ı��             *\n");
	printf("*           4.�޸�����             *\n");
	printf("*           5.�޸ĵ绰             *\n");
	printf("*           6.�޸���������         *\n");
	printf("*           7.�����ϼ��˵�         *\n");
	printf("************************************\n");
	printf("��ѡ��\n");
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
		printf("��������ȷ��ѡ��\n");
		findallemp();
	}
}

void updateAll(int i) {
	char ch[5], name[20], mail[25], id[20], tel[20];
	double date;
	printf("��������º�Ա������\n");
	scanf("%s", name);
	printf("��������º�Ա������\n");
	scanf("%s", mail);
	printf("��������º�Ա�����\n");
	scanf("%s", id);
	printf("��������º�Ա���绰\n");
	scanf("%s", tel);
	printf("��������º���������\n");
	scanf("%lf", &date);
	printf("ȷ�ϸ��¸�Ա����Ϣ��Y/N��\n");
	scanf("%s", ch);
	if(strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		if (sizeof(tel) != 11) {
			printf("����ʧ�ܣ��ֻ��Ŵ���\n");
			mainmenu();
			return;
		}
		for (int h = 0; h < empnum; h++) {
			if (strcmp(emplist[h].id, id) == 0) {
				printf("����ʧ�ܣ���Ա������Ѵ��ڣ�\n");
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
		printf("���³ɹ���\n");
		mainmenu();
	}
}

void updateName(int i) {
	char name[20], ch[5];
	printf("��������º�Ա������\n");
	scanf("%s", name);
	printf("ȷ�ϸ��¸�Ա����Ϣ��Y/N��\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		int j = 0;
		while (name[j] != '\0') {
			emplist[i].name[j] = name[j];
			j++;
		}
		printf("���³ɹ���\n");
	}

	updateemp2(i);
}

void updateId(int i) {
	char id[20], ch[5];
	printf("��������º�Ա�����\n");
	scanf("%s", id);
	printf("ȷ�ϸ��¸�Ա����Ϣ��Y/N��\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		int j = 0;
		while (id[j] != '\0') {
			emplist[i].id[j] = id[j];
			j++;
		}
		printf("���³ɹ���\n");
	}

	updateemp2(i);
}

void updateMail(int i) {
	char mail[20], ch[5];
	printf("��������º�Ա������\n");
	scanf("%s", mail);
	printf("ȷ�ϸ��¸�Ա����Ϣ��Y/N��\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		int j = 0;
		while (mail[j] != '\0') {
			emplist[i].mail[j] = mail[j];
			j++;
		}
		printf("���³ɹ���\n");
	}

	updateemp2(i);
}

void updateTel(int i) {
	char tel[20], ch[5];
	printf("��������º�Ա���绰\n");
	scanf("%s", tel);
	printf("ȷ�ϸ��¸�Ա����Ϣ��Y/N��\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		if (sizeof(tel) != 11) {
			printf("����ʧ�ܣ��ֻ��Ŵ���\n");
			mainmenu();
			return;
		}
		int j = 0;
		while (tel[j] != '\0') {
			emplist[i].tel[j] = tel[j];
			j++;
		}
		printf("���³ɹ���\n");
	}

	updateemp2(i);
}

void updateDate(int i) {
	double date, ch[5];
	printf("��������º���������\n");
	scanf("%lf", &date);
	printf("ȷ�ϸ��¸�Ա����Ϣ��Y/N��\n");
	scanf("%s", ch);
	if (strcmp(ch, "Y") == 0 || strcmp(ch, "y") == 0) {
		if (date > 0) {
			emplist[i].date = date;
			printf("���³ɹ���\n");
		}
		else {
			printf("�������ڲ���Ϊ�գ�����������\n");
			updateDate(i);
			return;
		}
	}

	updateemp2(i);
}

//ɾ��Ա��
void delemp() {
	char del[20],ch[5];
	printf("������Ҫɾ����Ա����Ż�����\n");
	scanf("%s", del);
	printf("\n");
	for (int i = 0; i < empnum; i++) {
		if (strcmp(emplist[i].id, del) == 0 || strcmp(emplist[i].name, del) == 0) {
			printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");
			printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
			printf("\n");
			printf("ȷ��ɾ����Ա����Y/N��\n");
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
				printf("ɾ���ɹ���\n");
				mainmenu();
				return;
			}
			else {
				mainmenu();
				return;
			}
		}
	}
	printf("����˾û�и�Ա����\n");
	mainmenu();
}

//����������
void sortbyname() {
	
	//�±�����
	int sort[100];
	//��������
	int sortname[100];
	
	int x = 0, flag = 0, g = 0, tmp = 0;
	printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");
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

//��������������
void sortbydate() {
	//������������
	double sortdate[100];
	//�±�����
	int sort[100];
	int j = 0, flag = 0, g = 0;
	double tmp = 0;
	printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");
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

//�����ֲ���Ա��
void findempbynameorid() {
	char nameid[20];
	int flag = 0;
	printf("���������Ա������������\n");
	scanf("%s", nameid);
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, nameid) || strstr(emplist[i].id, nameid)) {
			flag = 1;

		}
	}
	if (flag == 1) {
		printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");
	}
	else {
		printf("����˾û�и�Ա����\n");
	}
	for (int i = 0; i < empnum; i++) {
		if (strstr(emplist[i].name, nameid) || strstr(emplist[i].id, nameid)) {
			printf("%-16s%-32s%-24s%-16s%.2f\n", emplist[i].name, emplist[i].mail, emplist[i].id, emplist[i].tel, emplist[i].date);
			printf("\n");
		}
	}
	empmenu();
}

//���������ڲ���Ա��
void findempbydate() {
	int flag = 0;
	double start = 0, end = 0;
	printf("��������ʼ����(���磺2012.05,����0)\n");
	scanf("%lf", &start);
	printf("�������������(���磺2012.11,����0)\n");
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
		printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");
	}
	else {
		printf("��ʱ���û��Ա����ְ��\n");
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

//��ʾ����Ա����Ϣ
void findallemp() {
	int i = 0;
	printf("Ա���б�\n");
	printf("Name\t\tMail Address\t\t\tSingle User ID\t\tTelephone\t��������\n");

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
	printf("*          1.�������˵�             *\n");
	printf("*          2.����������             *\n");
	printf("*          3.��������������         *\n");
	printf("*          4.���������ڲ���Ա��     *\n");
	printf("*          5.�����ֱ�Ų���Ա��     *\n");
	printf("*          6.�˳�ϵͳ               *\n");
	printf("*************************************\n");
	printf("��ѡ��\n");
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
		printf("��������ȷ��ѡ��\n");
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
		printf("��������ȷ��ѡ��\n");
		findallemp();
	}
}

//��ȡ���ݿ⣬��ʼ��Ա������
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

//���˵�
void mainmenu() {
	printf("************************************\n");
	printf("*         ְԱ��Ϣ����ϵͳ         *\n");
	printf("*           1.���ְԱ             *\n");
	printf("*           2.ɾ��ְԱ             *\n");
	printf("*           3.�޸�ְԱ             *\n");
	printf("*           4.�鿴ְԱ             *\n");
	printf("*           5.�˳�ϵͳ             *\n");
	printf("************************************\n");
	printf("��ѡ��\n");
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
		printf("��������ȷ��ѡ��\n");
		mainmenu();
	}
}
int main(void) {

	iniemp();
	countnum();
	mainmenu();

	return 0;
}