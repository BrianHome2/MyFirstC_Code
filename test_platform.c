
/* SPDX-License-Identifier: GPL-2.0 */
/*  test Android Driver Sample Code for QCT platform
 *
 *  Copyright (C) 2021 test Corporation.
 *
 *  This software is licensed under the terms of the GNU General Public
 *  License version 2,  as published by the Free Software Foundation,  and
 *  may be copied,  distributed,  and modified under those terms.
 *
 *  This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */

#include "test_platform.h"

static int test_common_suspend(struct device *dev)
{
	return 0;
}

static int test_common_resume(struct device *dev)
{
	return 0;
}

int test_chip_common_probe(struct i2c_client *client,
		const struct i2c_device_id *id)
{
	int ret = 0;

	return ret;
}

int test_chip_common_remove(struct i2c_client *client)
{

	return 0;
}

static const struct i2c_device_id common_ts_id[] = {
	{test_common_NAME, 0 },
	{}
};

static const struct dev_pm_ops test_common_pm_ops = {
#if (!defined(HX_CONFIG_FB)) && (!defined(HX_CONFIG_DRM))
	.suspend = test_common_suspend,
	.resume  = test_common_resume,
#endif
};

#if defined(CONFIG_OF)
static const struct of_device_id test_match_table[] = {
	{.compatible = "test,hxcommon" },
	{},
};
#else
#define test_match_table NULL
#endif

static struct i2c_driver test_common_driver = {
	.id_table	= common_ts_id,
	.probe		= test_chip_common_probe,
	.remove		= test_chip_common_remove,
	.driver		= {
		.name = test_common_NAME,
		.owner = THIS_MODULE,
		.of_match_table = test_match_table,
#if defined(CONFIG_PM)
		.pm				= &test_common_pm_ops,
#endif
	},
};

static int __init test_common_init(void)
{
	I("driver init\n");

	i2c_add_driver(&test_common_driver);

	return 0;
}

static void __exit test_common_exit(void)
{
	i2c_del_driver(&test_common_driver);
}

module_init(test_common_init);
module_exit(test_common_exit);

MODULE_DESCRIPTION("test_common driver");
MODULE_LICENSE("GPL");

test

#include <stdio.h>

// Q1 計算字串長度的函式
int string_length(const char *str) {
    int length = 0;
    while (*str != '\0') {  // 繼續迭代直到遇到空字元
        length++;          // 每次增加一個計數
        str++;            // 移動到字串的下一個字元
    }
    return length;        // 返回字串的長度
}

int main() {
    const char *testString = "Hello, World!";
    int length = string_length(testString);
    printf("The length of the string \"%s\" is %d.\n", testString, length);
    return 0;
}

#include <stdio.h>
// Q2 寫一個 C 程式來交換兩個變數的值（不能使用額外變數）
int main() {
    int a = 5;
    int b = 10;

    printf("原始值: a = %d, b = %d\n", a, b);

    // 使用異或運算子來交換
    a = a ^ b;  // 第一步：a 現在是 a 和 b 的異或結果
    b = a ^ b;  // 第二步：b 現在是原始的 a
    a = a ^ b;  // 第三步：a 現在是原始的 b

    printf("交換後: a = %d, b = %d\n", a, b);
    return 0;
}


#include <stdio.h>
//Q3-1建立C 語言中的 struct 和 union 參數並用於計算字串長度（不能用 strlen）。

struct String {
    char *str;
    int length;
};

// 函式來計算字串長度
int calculateLength(struct String s) {
    int len = 0;
    while (*s.str != '\0') {
        len++;
        s.str++;
    }
    return len;
}

int main() {
    struct String myString;
    myString.str = "Hello, World!";
    
    int length = calculateLength(myString);
    printf("字串的長度是: %d\n", length);
    return 0;
}

#include <stdio.h>
//Q3-2建立C 語言中的 struct 和 union 參數並用於交換兩個變數的值（不使用額外變數）。
union Swap {
    int num[2];  // 用於儲存兩個整數
};

// 使用異或運運算元來交換
void swap(int *a, int *b) {
    *a = *a ^ *b; // 第一步：a 現在是 a 和 b 的異或結果
    *b = *a ^ *b; // 第二步：b 現在是原始的 a
    *a = *a ^ *b; // 第三步：a 現在是原始的 b
}

int main() {
    union Swap numbers;
    numbers.num[0] = 5;
    numbers.num[1] = 10;

    printf("原始值: a = %d, b = %d\n", numbers.num[0], numbers.num[1]);
    
    swap(&numbers.num[0], &numbers.num[1]);

    printf("交換後: a = %d, b = %d\n", numbers.num[0], numbers.num[1]);
    return 0;
}


#include <stdio.h>
#include <stdint.h>
//Q4 用c語言寫一個函式 reverse_bits()，可以反轉一個 uint8_t 變數的位元順序。
uint8_t reverse_bits(uint8_t n) {
    uint8_t reversed = 0;
    for (int i = 0; i < 8; i++) {
        // 將 n 的最低位元新增到 reversed 的最高位元上
        reversed <<= 1; // 左移 reversed，為下一位元騰出空間
        reversed |= (n & 1); // 將 n 的最低位元加到 reversed
        n >>= 1; // 右移 n，處理下一位元
    }
    return reversed;
}

int main() {
    uint8_t num = 0b11010010; // 例子：輸入一個數
    uint8_t reversed_num = reverse_bits(num);
    
    printf("Original: %u\n", num);
    printf("Reversed: %u\n", reversed_num);
    
    return 0;
}


#include <stdio.h>
//Q5 建立 static  function 寫一個 C 程式來交換兩個變數的值（不能使用額外變數)
static void swap(int *a, int *b) {
    *a = *a + *b; // 第一步：將兩個變數相加
    *b = *a - *b; // 第二步：計算新 b 的值
    *a = *a - *b; // 第三步：計算新 a 的值
}

int main() {
    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);
    
    swap(&x, &y); // 呼叫 swap 函式，傳遞 x 和 y 的地址

    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}



