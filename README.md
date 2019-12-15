Використовуючи засоби ООП, описати компанії, що розробляють та використовують технології. Для
компанії відома назва, список технологій, які дана компанія хоче розробляти, історія технологій,
розроблених в даній компанії (з датами початку та завершення розробки). Для технологій відома
назва, середні значення часу та коштів, потрібні для розробки, вартість ліцензування за період часу,
а також список технологій-вимог, від яких залежить дана технологія (для конкретної технології цей
список може бути пустим; не може бути циклічних залежностей, коли технологія А залежить від
технології В, а технологія В – від технології А).
Компанія може розробляти лише одну технологію в кожен момент часу. Одна технологія може
незалежно розроблятись кількома компаніями (при цьому час та кошти, витрачені на розробку в
кожній компанії, визначаються випадковим чином у певному діапазоні навколо середніх значень
для цієї технології). Компанія, що розробляє певну технологію, повинна мати доступ до всіх її вимог
– або розробивши ці технології, або ліцензувавши їх у іншої компанії. Ліцензування починається з
моменту, коли компанія починає використовувати технологію (тобто починає розробляти
технологію, яка залежить від даної) і продовжується постійно після цього. Компанії завжди
самостійно розробляють технології зі свого бажаного списку, але мають різні стратегії отримання
технологій-вимог:
 Компанія розробляє лише технології зі свого списку, ліцензує всі вимоги;
 Компанія розробляє самостійно всі вимоги, а також їх вимоги і т.д. – тобто нічого не ліцензує;
 Компанія має фіксований бюджет (часу та коштів) на розробку технологій-вимог,
намагається розробляти вимоги, поки вкладається в цей бюджет, всі інші ліцензує;
 Компанія задає певний період часу, для кожної технології-вимоги оцінює, чи витрати на
ліцензування за цей період перевищать витрати на самостійну розробки, і відповідно
розробляє самостійно чи ліцензує.
Реалізувати алгоритм для обчислення часу та загальних витрат на розробку заданого списку
технологій – включно з витратами на розробку чи ліцензування всіх вимог.
В інтерфейсі користувача реалізувати перегляд списку всіх технологій, можливість вибрати
технологію і подивитись деталі (список вимог, список компаній, які розробляють цю технологію).
Можливість вибрати список технологій і вивести час та витрати на розробку для різних компаній.
