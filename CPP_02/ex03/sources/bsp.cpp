/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsp.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 23:39:22 by fra           #+#    #+#                 */
/*   Updated: 2023/10/05 19:59:20 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool isUnderLine(Point const p1, Point const p2, Point const toCheck)
{
	Fixed m;
	Fixed q;

	m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	q = p1.getY() - m * p1.getX();
	return (toCheck.getY() < (m * toCheck.getX() + q));
}

static bool isAboveLine(Point const p1, Point const p2, Point const toCheck)
{
	Fixed m;
	Fixed q;

	m = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	q = p1.getY() - m * p1.getX();
	return (toCheck.getY() > (m * toCheck.getX() + q));
}

static bool checkInput( Point const a, Point const b, Point const c )
{
	if ((isUnderLine(a, b, c) == false) and (isAboveLine(a, b, c) == false))
	{
		std::cout << "Points on the same line" << std::endl;
		return (false);
	}
	else if (((a.getX() == b.getX()) and (a.getY() == b.getY())) or
			((a.getX() == c.getX()) and (a.getY() == c.getY())) or
			((b.getX() == c.getX()) and (a.getY() == c.getY())))
	{
		std::cout << "Two or more points overlapping" << std::endl;
		return (false);
	}
	else
		return (true);
}

static Point const findMax( Point const a, Point const b, Point const c )
{
	Point max = a;
	
	if (max.getY() < b.getY())
		max = b;
	if (max.getY() < c.getY())
		max = c;
	return (max);
}

static Point const findLeft( Point const a, Point const b, Point const c, Point const max )
{
	Point left = a;

	if (a == max)
	{
		left = b;
		if (left.getX() > c.getX())
			left = c;
	}
	else if (b == max)
	{
		if (left.getX() > c.getX())
			left = c;
	}
	else
	{
		if (left.getX() > b.getX())
			left = b;
	}
	return (left);
}

static Point const findRight( Point const a, Point const b, Point const c, Point const max )
{
	Point right = a;

	if (a == max)
	{
		right = b;
		if (right.getX() < c.getX())
			right = c;
	}
	else if (b == max)
	{
		if (right.getX() < c.getX())
			right = c;
	}
	else
	{
		if (right.getX() < b.getX())
			right = b;
	}
	return (right);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Point const	max = findMax(a, b, c);
	Point const	left = findLeft(a, b, c, max);
	Point const	right = findRight(a, b, c, max);

	if (checkInput(a, b, c) == false)
		return (false);
	if ((max.getX() < left.getX()) or (max.getX() > right.getX()))
		return (bsp(Point(a.getX(), a.getY() * Fixed(-1)),
					Point(b.getX(), b.getY() * Fixed(-1)),
					Point(c.getX(), c.getY() * Fixed(-1)), 
					Point(point.getX(), point.getY() * Fixed(-1))));

	if (isAboveLine(left, right, point))
	{
		if (point.getX() < max.getX())
			return (isUnderLine(left, max, point));
		else
			return (isUnderLine(max, right, point));
	}
	else
		return (false);
}