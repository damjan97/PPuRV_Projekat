/*
 * main.c
 *
 *  Креирано 19.10.2018.
 *      Аутор: Дамјан Гламочић RA65/2015
 */

/*
 *
 * Опис задатка:
 * Написати функцију која прима један природан број као параметар и на стандардни излаз
 * исписује све природне бројеве мање од тог броја чији запис је палиндром. Функција уједно
 * прима и параметар који говори у ком бројном систему број треба да буде палиндром, али се
 * може само бирати између три бројна система: окталног, декадног и хексадецималног.
 * (Палиндром је низ које је централно симетричан, тј. чита се исто и са лева и са десна).
 *
 */

/*
 *
 * Програм је тестиран за што више могућих случајева и у свим је радио без икаквих багова.
 * Тестирање се састоји из бесконачне петље која се врти све док корисник не унесе
 * одговарајућу вриједност која означава излазак из петље.
 * У тест програму се од корисника очекује да унесе одговарајући број којим означава у ком
 * бројном систему жели да програм рачуна палиндромске бројеве. Након тога уноси број,
 * и програм исписује на стандардни излаз све палиндромеске бројеве мање од тог броја,
 * у сва трбројна система, како би сам корисник лакше утврдио тачност програма.
 *
 */

/*
 *
 * Ради што веће уштеде меморије, сви палиндромски бројеви се смијештају у једноструко спрегнуту
 * листу. Тиме се губи на брзини рада програма, али се не заузима више меморије него што треба.
 * Пошто не постоји начин да се унапред израчуна тачан број палиндромских бројева мањих од неког
 * унапред задатог броја, овај начин се намеће као логички најисправнији. Како би се мало уштедило
 * на брзини, за свако рачунање се не врши провјера сваког броја, од нуле па надање, да ли је
 * палиндромски, него само од посљедњег елемента из листе, уједно и највећег. Нема потребе да се
 * исте провјере врше више пута. Провјера да ли је број палиндромски у одговарајућем бројном систему
 * је одрађена преко низа показивача на функције које раде посебно провјеру за сваки од три бројна
 * система. Разлог такве имплементације је избјегавања гранање помоћу if-else или switch-case, јер
 * је од њега бржи приступ помоћу индексирања.
 *
 */

/*
 *
 * Током писања кода, придржавао сам се MISRA стандарда колико је то било могуће. Неколико правила
 * нисам испоштовао: динамичку алокацију меморије помоћу функције malloc(), њено ослобађање помоћу
 * функције free(), то је било неопходно због имплементације једноструко спрегнуте листе;
 * користио сам неке функције из stdio.h библиотеке које нису дозвољене по MISRA стандарду,
 * попут printf(), fprintf(), scanf(), у неком случају сам морао, јер се тако тражило
 * у опису задатка, а накада сам се одлучио за то ради боље комуникације са корисником током
 * тестирања.
 *
 */

#include "palindrom.h"

int_least32_t main(void);

int_least32_t main(void)
{
	uint_least32_t num;
	uint_fast8_t num_system;

	Node* heads[3];
	heads[0] = (Node*) malloc(sizeof(Node));
	heads[1] = (Node*) malloc(sizeof(Node));
	heads[2] = (Node*) malloc(sizeof(Node));

	while (1)
	{
		printf("\nUnesite brojni sistem koji zelite da koristite:\n");
		printf("1. Oktalni\n");
		printf("2. Dekadni\n");
		printf("3. Heksadecimalni\n");
		printf("4. Kraj programa\n");
		printf(" >> ");
		scanf("%"SCNuFAST8, &num_system);

		if (num_system == (uint_fast8_t) 4)
		{
			break;
		}

		printf("\nUnesite broj:\n >> ");
		scanf("%"SCNuLEAST32, &num);

		calculate_palindromic_numbers(heads[num_system - (uint_fast8_t) 1], num, num_system);

	}

	clear_list(&heads[0]);
	clear_list(&heads[1]);
	clear_list(&heads[2]);

	printf("\nKraj programa!\n");

	return (int_least32_t) 0;
}

