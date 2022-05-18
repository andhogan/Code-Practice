import utils
import sorts

bookshelf = utils.load_books('books_small.csv')

for book in bookshelf:
  book['author_lower'] = book['author'].lower()
  book['title_lower'] = book['title'].lower()
  #print(book['title'])
#print(ord("z"))
#print(ord("Z"))
#print(ord("a"))
#print(ord("A"))
#print(ord(" "))
def by_title_ascending(book_a, book_b):
  return book_a['title_lower'] > book_b['title_lower']

def by_author_ascending(book_a, book_b):
  return book_a['author_lower'] > book_b['author_lower']

def by_total_length(book_a, book_b):
  return len(book_a['author_lower']) + len(book_a['title_lower']) > len(book_b['author_lower']) + len(book_b['title_lower'])

bookshelf_v1 = bookshelf.copy()
sort_1 = sorts.bubble_sort(bookshelf_v1, by_title_ascending)
#sort_2 = sorts.bubble_sort(bookshelf_v1, by_author_ascending)
bookshelf_v2 = bookshelf.copy()
sorts.quicksort(bookshelf.copy(), 0, len(bookshelf.copy()) -1, by_author_ascending)
#for book in sort_1:
  #print("\n"+book['title'])

long_bookshelf = utils.load_books('books_large.csv')

for book in long_bookshelf:
  book['author_lower'] = book['author'].lower()
  book['title_lower'] = book['title'].lower()
#sort_3 = sorts.bubble_sort(long_bookshelf, by_total_length)
sort_4 = sorts.quicksort(long_bookshelf, 0, len(long_bookshelf) - 1,by_total_length)