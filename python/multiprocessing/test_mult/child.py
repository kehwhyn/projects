import time


def f(conn):
    with conn:
        conn.send([42, None, 'hello'])
        time.sleep(25)
        print(conn.recv())
    # conn.close()
