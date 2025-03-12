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

#define version V001

int sum(int a, int b)
{
	int sum_value = 0;
	
	sum_value = a+b;

	return sum_value;
}

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
	
	ret = sum(10,20);
	
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
