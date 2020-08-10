#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import multiprocessing as mp
from test_mult.child import f
import time


# def f(conn):
#    with conn:
#        conn.send([42, None, 'hello'])
#        print(conn.recv())
#    # conn.close()


if __name__ == '__main__':
    ctx = mp.get_context("spawn")
    parent_conn, child_conn = ctx.Pipe()
    p = ctx.Process(target=f, args=(child_conn,))
    p.start()
    with parent_conn:
        time.sleep(15)
        print(parent_conn.recv())   # prints "[42, None, 'hello']"
        time.sleep(30)
        parent_conn.send(["Hello", "from", "parent"])
    p.join()
