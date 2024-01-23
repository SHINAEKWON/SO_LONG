# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shikwon <shikwon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:03:38 by shikwon           #+#    #+#              #
#    Updated: 2023/08/28 22:58:23 by shikwon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

MY_SOURCES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_strnstr2.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_strncmp.c

MY_SOURCES_BONUS = ft_lstnew.c \
		   ft_lstadd_back.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstdelone.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_lstclear.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

MY_OBJECTS_BONUS = $(MY_SOURCES_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

AR = ar rcs

$(NAME): ${MY_OBJECTS}
	${AR} ${NAME} ${MY_OBJECTS}
	
bonus: ${MY_OBJECTS_BONUS} ${MY_OBJECTS}
	${AR} ${NAME} ${MY_OBJECTS_BONUS} ${MY_OBJECTS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
clean:
	${RM} ${MY_OBJECTS} ${MY_OBJECTS_BONUS} 
	
fclean:	clean
	${RM} $(NAME)
	${RM} libft.so

re:	fclean all

so:
	${CC} -nostartfiles -fPIC ${CFLAGS} -c ${MY_SOURCES} ${MY_SOURCES_BONUS}
	${CC} -nostartfiles -shared -o libft.so ${MY_OBJECTS} ${MY_OBJECTS_BONUS}

.PHONY: all clean fclean re so

