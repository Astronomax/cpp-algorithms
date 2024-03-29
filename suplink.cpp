void update(int v, int pos) { //поднимаюсь по суфссылкам вверх и сразу считаю для каждой суперссылку
		if (v == 0)
			return;
		int last = v; //последняя терминальная вершина

		while (v != 0) {
			if (!g[v].term.empty() && v != last) { //если терминальная
				g[last].suplink = v; //суперссылка из предыдущей указвает на эту
				last = v; //новая терминальная
			}

			if (g[v].suplink == -1) //если есть возможность, предпочительнее перейти по суперссылке
				v = get_link(v);
			else
				v = g[v].suplink;
		}
	}
