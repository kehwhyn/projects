import unittest
from main import fibonacci

class TestFibonacci(unittest.TestCase):

    def testFor1(self):
        self.assertEqual(fibonacci(1), 1)

    def testFor2(self):
        self.assertEqual(fibonacci(2), 2)

    def testForNth(self):
        self.assertEqual(fibonacci(300), 359579325206583560961765665172189099052367214309267232255589801)

    def testTypes(self):
      with self.assertRaises(TypeError):
          fibonacci("str")
          fibonacci(True)
          fibonacci(3+5j)

    def testValue(self):
        self.assertRaises(ValueError, fibonacci, -2)

if __name__ == '__main__':
    unittest.main()
