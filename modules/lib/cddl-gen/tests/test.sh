#!/bin/bash
#
# Copyright (c) 2020 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: Apache-2.0
#

pycodestyle ../cddl_gen/cddl_gen.py --max-line-length=100 --ignore=W191,E101,W503
[[ $? -ne 0 ]] && exit 1
pycodestyle ../cddl_gen/__init__.py --max-line-length=100
[[ $? -ne 0 ]] && exit 1
pycodestyle ../setup.py --max-line-length=100
[[ $? -ne 0 ]] && exit 1
pycodestyle scripts/run_tests.py --max-line-length=100 --ignore=W503,E501,E402
[[ $? -ne 0 ]] && exit 1
pycodestyle scripts/release_test.py --max-line-length=100
[[ $? -ne 0 ]] && exit 1

pushd "scripts"
python3 -m unittest run_tests
[[ $? -ne 0 ]] && popd && exit 1
popd

if [[ -z "$ZEHPYR_BASE" ]]; then
        ZEPHYR_BASE=$(west topdir)/zephyr
fi

$ZEPHYR_BASE/scripts/twister -M -v -T . -W --platform native_posix --platform native_posix_64
